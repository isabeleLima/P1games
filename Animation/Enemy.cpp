/**********************************************************************************
// Alien (Arquivo de Cabeçalho)
//
// Criação:     21 Dez 2012
// Atualização: 26 Fev 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Alienígena do jogo Galaga
//
**********************************************************************************/

#include "Enemy.h"
#include "index.h"
#include "Level1.h"

// ---------------------------------------------------------------------------------

Enemy::Enemy(TileSet* tiles)
{
    type = ENEMY;

    spriteAnimation = new Animation(tiles, 0.5f, true);
    int y = -(tiles->TileHeight() / 2.0f);
    int x = 230 + (rand() % (window->Width() - 460));
    MoveTo(x, y,  Layer::FRONT);
    vel = 70.0f;

    BBox(new Rect(-30, -40, 30, 49));
}

// ---------------------------------------------------------------------------------

Enemy::~Enemy()
{
    delete spriteAnimation;
}

// ---------------------------------------------------------------------------------

void Enemy::Update()
{
    SpriteData sprite = spriteAnimation->ReturnSprite();
    spriteAnimation->NextFrame();
    // desloca alien
    Translate(0.0f, vel * gameTime);
    if (y + sprite.height / 2.0f > 540)
        window->Close();
}

void Enemy::OnCollision(Object* obj) {
    if (obj->Type() == ARROW)
        ArrowCollision(obj);
}

void Enemy::ArrowCollision(Object* obj) {
    Level1::scene->Delete();
}

// ---------------------------------------------------------------------------------
