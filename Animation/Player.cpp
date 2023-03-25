/**********************************************************************************
// Player (Arquivo de Cabe�alho)
//
// Cria��o:     21 Dez 2012
// Atualiza��o: 26 Fev 2023
// Compilador:  Visual C++ 2022
//
// Descri��o:   Player do jogo Galaga
//
**********************************************************************************/

#include "Player.h"
#include "Arrow.h"
#include "Home.h"
#include "Level1.h"


// ---------------------------------------------------------------------------------

Player::Player(TileSet* tiles)
{
    //sprite = new Sprite("Resources/player.png");
    
    spriteAnimation = new Animation(tiles, 0.7f, true);

    arrow = new Image("Resources/arrow.png");

    MoveTo(window->CenterX(), window->Height() - 50.0f, Layer::FRONT);
    vel = 250;
}

// ---------------------------------------------------------------------------------

Player::~Player()
{
    delete spriteAnimation;
    delete arrow;
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
    // dispara um m�ssil com a barra de espa�o
    //if (window->KeyPress(VK_SPACE))
    //{
        // tamanho do m�ssel � 26x30
       // Arrow* a = new Arrow(arrow);
       // a->MoveTo(x, y - sprite->Height() / 2.0f, Layer::FRONT);
       // Level1::scene->Add(a, MOVING);
   // }

    // desloca nave horizontalmente
    if (window->KeyDown(VK_RIGHT))
        Translate(vel * gameTime, 0);
    if (window->KeyDown(VK_LEFT))
        Translate(-vel * gameTime, 0);

     //mant�m nave dentro da janela

    SpriteData sprite = spriteAnimation->ReturnSprite();
    

    if (x - sprite.width / 2.0f < 0)
       MoveTo(sprite.width / 2.0f, y);
    if (x + sprite.width / 2.0f > window->Width())
        MoveTo(window->Width() - sprite.width / 2.0f, y);

    spriteAnimation->NextFrame();
}

// ---------------------------------------------------------------------------------
