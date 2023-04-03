/**********************************************************************************
// Animation
// 
// Criação:     10 Abr 2012
// Atualização: 07 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Exemplo de uso da classe Animation
//
**********************************************************************************/

#include "Engine.h"
#include "Game.h"
#include "TileSet.h"
#include "Animation.h"
#include "Resources.h"
#include "Level1.h"
#include "Sprite.h"
#include "Player.h"
#include "Enemy.h"
#include "Home.h"
#include "Over.h"

#include <iostream>
#include <chrono>
#include <thread>
// ------------------------------------------------------------------------------

Scene* Level1::scene = nullptr;
bool Level1::over = false;
auto start = std::chrono::high_resolution_clock::now();
// -----------------------------------------------------------------------------

void Level1::Init()
{
    Level1::over = false;
    // cria gerenciador de cena
    scene = new Scene();
    enemyInterval = 1500000;

    backSet = new TileSet("Resources/spriteV4.png", 960, 540, 6, 36);
    yoshi = new TileSet("Resources/spriteGrass.png", 960, 540, 2, 12);

    spritePlayer = new TileSet("Resources/playerSpriteV2.png", 96, 96, 2, 4);

    backAnim = new Animation(backSet, 0.035f, true);
    yoshiAnim = new Animation(yoshi, 0.09f, true);

    // cria jogador
    Player* player = new Player(spritePlayer);
    scene->Add(player, MOVING);
 
}

// ------------------------------------------------------------------------------

void Level1::Update()
{
    if (window->KeyPress('B'))
    {
        viewBBox = !viewBBox;
    }

    if (window->KeyPress(VK_ESCAPE))
    {
        // volta para a tela de abertura
        Engine::Next<Home>();
    }
    else if (over || window->KeyPress(VK_RETURN)) {
        Engine::Next<Over>();
    }
    else
    {
        auto end = std::chrono::high_resolution_clock::now(); // tempo final
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start); // tempo total em microssegundos


        if (duration.count() >= enemyInterval) {
            start = std::chrono::high_resolution_clock::now();
            enemyInterval -= 15000;

            int radom = 0 + (rand() % 2);
            int hp;
            if (radom % 2 == 0) {
                SpriteEnemy = new TileSet("Resources/enemy1Sprite.png", 96, 96, 2, 2);
                hp = 1;
            }
            else {
                SpriteEnemy = new TileSet("Resources/enemy2Sprite.png", 96, 96, 2, 2);
                hp = 0;
            }

            Enemy* enemy = new Enemy(SpriteEnemy, hp);
            scene->Add(enemy, STATIC);
        }

        // atualiza animação
        scene->Update();

        backAnim->NextFrame();
        yoshiAnim->NextFrame();

        scene->CollisionDetection();
    }
} 

// ------------------------------------------------------------------------------

void Level1::Draw()
{
    backAnim->Draw(window->CenterX(), window->CenterY(), Layer::FRONT);
    yoshiAnim->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
    scene->Draw();

    if (viewBBox)
        scene->DrawBBox();
} 

// ------------------------------------------------------------------------------

void Level1::Finalize()
{
    delete backSet;
    delete backAnim;
    delete yoshi;
    delete yoshiAnim;
    delete SpriteEnemy;
    delete scene;
    delete backg;
    delete arrow;
    delete spritePlayer;
}

 