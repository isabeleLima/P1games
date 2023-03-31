/**********************************************************************************
// Alien (Arquivo de Cabe�alho)
//
// Cria��o:     21 Dez 2012
// Atualiza��o: 26 Fev 2023
// Compilador:  Visual C++ 2022
//
// Descri��o:   Alien�gena do jogo Galaga
//
**********************************************************************************/

#ifndef _GALAGA_ALIEN_H_
#define _GALAGA_ALIEN_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"          // tipos espec�ficos da engine
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

    void OnCollision(Object* obj);     // resolu��o da colis�o
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