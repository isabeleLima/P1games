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


// ---------------------------------------------------------------------------------

Player::Player(TileSet* tiles)
{
    //sprite = new Sprite("Resources/player.png");
    
    spriteAnimation = new Animation(tiles, 0.7f, true);

    arrow = new Image("Resources/arrow.png");

    MoveTo(window->CenterX(), window->Height() - 50.0f, Layer::FRONT);
    vel = 250;
}

// ---------------------------------------------------------------------------------

Player::~Player()
{
    delete spriteAnimation;
    delete arrow;
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
    // dispara um míssil com a barra de espaço
    //if (window->KeyPress(VK_SPACE))
    //{
        // tamanho do míssel é 26x30
       // Arrow* a = new Arrow(arrow);
       // a->MoveTo(x, y - sprite->Height() / 2.0f, Layer::FRONT);
       // Level1::scene->Add(a, MOVING);
   // }

    // desloca nave horizontalmente
    if (window->KeyDown(VK_RIGHT))
        Translate(vel * gameTime, 0);
    if (window->KeyDown(VK_LEFT))
        Translate(-vel * gameTime, 0);

     //mantém nave dentro da janela

    SpriteData sprite = spriteAnimation->ReturnSprite();
    

    if (x - sprite.width / 2.0f < 0)
       MoveTo(sprite.width / 2.0f, y);
    if (x + sprite.width / 2.0f > window->Width())
        MoveTo(window->Width() - sprite.width / 2.0f, y);

    spriteAnimation->NextFrame();
}

// ---------------------------------------------------------------------------------
