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

#include "Engine.h"
#include "Over.h"
#include "Hit.h"

// ---------------------------------------------------------------------------------

Enemy::Enemy(TileSet* tiles, int hp)
{
    type = ENEMY;
    this->hp = hp;

    spriteAnimation = new Animation(tiles, 0.5f, true);
    int y = -(tiles->TileHeight() / 2.0f);
    int x = 230 + (rand() % (window->Width() - 460));
    MoveTo(x, y,  Layer::FRONT);
    vel = 100.0f;

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
    if (y + sprite.height / 2.0f > 540) {
        Level1::over = true;
    }
        
}

void Enemy::OnCollision(Object* obj) {
    if (obj->Type() == ARROW)
        ArrowCollision(obj);
}

void Enemy::ArrowCollision(Object* obj) {
    hp -= 1;
    Hit* hit = new Hit(new TileSet("Resources/spriteHit.png", 32, 64, 2, 2), obj->X(), obj->Y());
    Level1::scene->Add(hit, STATIC);

    Level1::scene->Delete(obj, MOVING);  
}

// ---------------------------------------------------------------------------------
