/**********************************************************************************
// Level1 (Arquivo de Cabeçalho)
//
// Criação:     18 Jan 2013
// Atualização: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Nível 1 do jogo PacMan
//
**********************************************************************************/

#ifndef _PACMAN_LEVEl1_H_
#define _PACMAN_LEVEL1_H_

// ------------------------------------------------------------------------------
// Inclusões

#include "Game.h"
#include "Sprite.h"
#include "Scene.h"

#include "TileSet.h"
#include "Animation.h"


// ------------------------------------------------------------------------------

class Level1 : public Game
{
private:
    Sprite* backg = nullptr;       // background
    bool viewBBox = false;          // habilita visualização da bounding box

    Image* arrow;           // imagem do míssil

    TileSet* backSet = nullptr;
    Animation* backAnim = nullptr;

    TileSet* yoshi = nullptr;
    Animation* yoshiAnim = nullptr;

    TileSet* spritePlayer;            // sprite do player
    TileSet* SpriteEnemy;            // sprite do player

public:
    static Scene* scene;
    void Init();                    // inicializa jogo
    void Update();                  // atualiza lógica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza jogo
};

// -----------------------------------------------------------------------------

#endif