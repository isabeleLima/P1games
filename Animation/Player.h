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

#ifndef _GAME_PLAYER_H_
#define _GAME_PLAYER_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"              // tipos espec�ficos da engine
#include "Object.h"             // interface de object
#include "Sprite.h"             // interface de sprites
#include "TileSet.h"
#include "Animation.h"
// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
   
    Animation* spriteAnimation;
    Image* arrow;           // imagem do m�ssil
    float vel;                  // velocidade horizontal

public:
    Player(TileSet* tiles);
    ~Player();

    void Update();
    void Draw();
};

// ---------------------------------------------------------------------------------

inline void Player::Draw()
{
    spriteAnimation->Draw(x,y, Layer::FRONT);
}

// ---------------------------------------------------------------------------------

#endif
