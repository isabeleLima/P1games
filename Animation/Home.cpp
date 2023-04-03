/**********************************************************************************
// Home (Código Fonte)
//
// Criação:     18 Jan 2013
// Atualização: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Tela de abertura do jogo PacMan
//
**********************************************************************************/

#include "Engine.h"
#include "Home.h"
#include "Level1.h"

// ------------------------------------------------------------------------------

void Home::Init()
{
    backg = new Sprite("Resources/home.png");

    enter = new TileSet("Resources/enter.png", 960, 540, 2, 4);
    enterAnimation = new Animation(enter, 0.30f, true);
}

// ------------------------------------------------------------------------------

void Home::Finalize()
{
    delete enterAnimation;
    delete backg;
    delete enter;
}

// ------------------------------------------------------------------------------

void Home::Update()
{
    enterAnimation->NextFrame();

    // sai do jogo com a tecla ESC
    if (window->KeyPress(VK_ESCAPE))
        window->Close();

    // passa ao primeiro nível com ENTER
    if (window->KeyPress(VK_RETURN))
        Engine::Next<Level1>();
}

// ------------------------------------------------------------------------------

void Home::Draw()
{
    enterAnimation->Draw(window->CenterX(), window->CenterY(), Layer::FRONT);
    backg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
}

// ------------------------------------------------------------------------------