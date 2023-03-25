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
// ---------------------------------------------------------------------------------

Arrow::Arrow(Image* img)
{
    sprite = new Sprite(img);
    MoveTo(window->CenterX(), window->Height() - 50.0f, Layer::FRONT);
    vel = 250;
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

// ---------------------------------------------------------------------------------
