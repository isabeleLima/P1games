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
    // m�ssil se move apenas no eixo y
    Translate(0, -vel * gameTime);

    // remove m�sseis que saem da janela
    if (y < 0)
       Level1::scene->Delete();
}

void Arrow::OnCollision(Object* obj) {

}

// ---------------------------------------------------------------------------------
