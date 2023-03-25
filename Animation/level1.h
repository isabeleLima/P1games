/**********************************************************************************
// Level1 (Arquivo de Cabe�alho)
//
// Cria��o:     18 Jan 2013
// Atualiza��o: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descri��o:   N�vel 1 do jogo PacMan
//
**********************************************************************************/

#ifndef _PACMAN_LEVEl1_H_
#define _PACMAN_LEVEL1_H_

// ------------------------------------------------------------------------------
// Inclus�es

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
    bool viewBBox = false;          // habilita visualiza��o da bounding box

    Image* arrow;           // imagem do m�ssil

    TileSet* backSet = nullptr;
    Animation* backAnim = nullptr;

    TileSet* yoshi = nullptr;
    Animation* yoshiAnim = nullptr;

    TileSet* spritePlayer;            // sprite do player
    TileSet* SpriteEnemy;            // sprite do player

public:
    static Scene* scene;
    void Init();                    // inicializa jogo
    void Update();                  // atualiza l�gica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza jogo
};

// -----------------------------------------------------------------------------

#endif