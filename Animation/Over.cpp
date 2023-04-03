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
#include "Over.h"
#include "Level1.h"

// ------------------------------------------------------------------------------

void Over::Init()
{
    backg = new Sprite("Resources/gameOver.png");

    enter = new TileSet("Resources/over.png", 960, 540, 2, 4);
    enterAnimation = new Animation(enter, 0.30f, true);
}

// ------------------------------------------------------------------------------

void Over::Finalize()
{
    delete enterAnimation;
    delete backg;
    delete enter;
}

// ------------------------------------------------------------------------------

void Over::Update()
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

void Over::Draw()
{
    enterAnimation->Draw(window->CenterX(), window->CenterY(), Layer::FRONT);
    backg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
}

// ------------------------------------------------------------------------------