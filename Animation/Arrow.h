/**********************************************************************************
// Missile (Arquivo de Cabeçalho)
//
// Criação:     21 Dez 2012
// Atualização: 26 Fev 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Mísseis do jogo Galaga
//
**********************************************************************************/

#ifndef _GALAGA_MISSILE_H_
#define _GALAGA_MISSILE_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"              // tipos específicos da engine
#include "Object.h"             // interface de object
#include "Sprite.h"             // interface de sprites
#include "Image.h"              // interface de image
#include "Scene.h"
// ---------------------------------------------------------------------------------

class Arrow : public Object
{
private:
    Sprite* sprite;
    float vel;

public:
    Arrow(Image* img);
    ~Arrow();

    void Update();
    void Draw();
};
 
// ---------------------------------------------------------------------------------
// Funções Membro Inline
inline void Arrow::Draw()
{
    sprite->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif
