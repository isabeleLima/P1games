/**********************************************************************************
// Alien (Arquivo de Cabeçalho)
//
// Criação:     21 Dez 2012
// Atualização: 26 Fev 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Alienígena do jogo Galaga
//
**********************************************************************************/

#ifndef _GALAGA_ALIEN_H_
#define _GALAGA_ALIEN_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"          // tipos específicos da engine
#include "Object.h"         // interface de object
#include "Sprite.h"         // interface de sprites
#include "TileSet.h"
#include "Animation.h"
#include <string>           // string da biblioteca STL
using std::string;          // usa string sem std::

// ---------------------------------------------------------------------------------

class Enemy : public Object
{
private:
    Animation* spriteAnimation;
    float vel;

public:
    Enemy(TileSet* tiles);
    ~Enemy();

    void OnCollision(Object* obj);     // resolução da colisão
    void ArrowCollision(Object* obj);

    void Update();
    void Draw();
};

// ---------------------------------------------------------------------------------

inline void Enemy::Draw()
{
    spriteAnimation->Draw(x, y, Layer::FRONT);
}

// ---------------------------------------------------------------------------------

#endif