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

// ---------------------------------------------------------------------------------

Arrow::Arrow(Image* img)
{
    type = ARROW;

    sprite = new Sprite(img);
    vel = 250;

    BBox(new Rect(x - 5, y - 5, x + 4, y + 4));
}

// ---------------------------------------------------------------------------------

Arrow::~Arrow()
{
    delete sprite;
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

}

// ---------------------------------------------------------------------------------
