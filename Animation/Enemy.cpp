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

// ---------------------------------------------------------------------------------

Enemy::Enemy(TileSet* tiles)
{
    spriteAnimation = new Animation(tiles, 0.5f, true);
    int y = 0 + (rand() % 100);
    int x = 60 + (rand() % 500);
    MoveTo(x, y,  Layer::FRONT);
    vel = 70.0f;
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

// ---------------------------------------------------------------------------------
