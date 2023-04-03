/**********************************************************************************
// Missile (Código Fonte)
//
// Criação:     21 Dez 2012
// Atualização: 26 Fev 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Mísseis do jogo Galaga
//
**********************************************************************************/

#include "Arrow.h"
#include "Level1.h"
#include "Scene.h"
#include "index.h"
#include "Enemy.h"

// ---------------------------------------------------------------------------------

Arrow::Arrow(TileSet* tiles)
{
    type = ARROW;

    spriteAnimation = new Animation(tiles, 0.5f, true);
    vel = 450;

    BBox(new Rect(x - 5, y - 5, x + 4, y + 4));
}

// ---------------------------------------------------------------------------------

Arrow::~Arrow()
{
    delete spriteAnimation;
}

// ---------------------------------------------------------------------------------

void Arrow::Update()
{
    // míssil se move apenas no eixo y
    Translate(0, -vel * gameTime);

    // remove mísseis que saem da janela
    if (y < 0)
        Level1::scene->Delete();
}

void Arrow::OnCollision(Object* obj) {
    if (obj->Type() == ENEMY)
        EnemyCollision(obj);
}

void Arrow::EnemyCollision(Object* obj) {
    Enemy* e = (Enemy*)obj;

    if (e->hp <= 0) {
        Level1::scene->Delete(obj, STATIC);
    }
}

// ---------------------------------------------------------------------------------
