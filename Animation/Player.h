/**********************************************************************************
// Player (Arquivo de Cabeçalho)
//
// Criação:     21 Dez 2012
// Atualização: 26 Fev 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Player do jogo Galaga
//
**********************************************************************************/

#ifndef _GAME_PLAYER_H_
#define _GAME_PLAYER_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"              // tipos específicos da engine
#include "Object.h"             // interface de object
#include "Sprite.h"             // interface de sprites
#include "TileSet.h"
#include "Animation.h"
// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
   
    Animation* spriteAnimation;
    Image* arrow;           // imagem do míssil
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
