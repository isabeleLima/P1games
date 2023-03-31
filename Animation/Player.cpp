/**********************************************************************************
// Player (Arquivo de Cabeçalho)
//
// Criação:     21 Dez 2012
// Atualização: 26 Fev 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Player do jogo Galaga
//
**********************************************************************************/

#include "Player.h"
#include "Arrow.h"
#include "Home.h"
#include "Level1.h"
#include "index.h"


// ---------------------------------------------------------------------------------

Player::Player(TileSet* tiles)
{
    type = PLAYER;

    spriteAnimation = new Animation(tiles, 0.7f, true);

    arrow = new Image("Resources/enemy1.png");
    arrowTimer.Start();

    BBox(new Rect(-30, -40, 30, 49));
    MoveTo(window->CenterX(), window->Height() - 50.0f, Layer::FRONT);
    vel = 250;
}

// ---------------------------------------------------------------------------------

Player::~Player()
{
    delete spriteAnimation;
    delete arrow;
}

void Player::OnCollision(Object* obj)
{
    if (obj->Type() == ENEMY)
        EnemyCollision(obj);
}

void Player::EnemyCollision(Object* obj)
{
    window->Close();
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
    SpriteData sprite = spriteAnimation->ReturnSprite();

    if (window->KeyDown(VK_SPACE))
    {
        if (arrowTimer.Elapsed(0.4)) {
            arrowTimer.Reset();
            // tamanho do míssel é 26x30
            Arrow* m = new Arrow(new Image("Resources/enemy1.png"));
            m->MoveTo(x, y - sprite.height / 2.0f, Layer::UPPER);
            Level1::scene->Add(m, MOVING);
        }
    }

    // desloca nave horizontalmente
    if (window->KeyDown(VK_RIGHT))
        Translate(vel * gameTime, 0);
    if (window->KeyDown(VK_LEFT))
        Translate(-vel * gameTime, 0);

    int bounds = 200;
    // mantém nave dentro da janela
    if (x - sprite.width / 2.0f < bounds)
        MoveTo(sprite.width / 2.0f + bounds, y);
    if (x + sprite.width / 2.0f > window->Width() - bounds)
        MoveTo(window->Width() - bounds - sprite.width / 2.0f, y);

    spriteAnimation->NextFrame();
}

// ---------------------------------------------------------------------------------
