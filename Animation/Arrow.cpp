/**********************************************************************************
// Missile (C�digo Fonte)
//
// Cria��o:     21 Dez 2012
// Atualiza��o: 26 Fev 2023
// Compilador:  Visual C++ 2022
//
// Descri��o:   M�sseis do jogo Galaga
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
    // m�ssil se move apenas no eixo y
    Translate(0, -vel * gameTime);

    // remove m�sseis que saem da janela
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
