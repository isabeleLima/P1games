/**********************************************************************************
// Missile (Arquivo de Cabe�alho)
//
// Cria��o:     21 Dez 2012
// Atualiza��o: 26 Fev 2023
// Compilador:  Visual C++ 2022
//
// Descri��o:   M�sseis do jogo Galaga
//
**********************************************************************************/

#ifndef _GALAGA_MISSILE_H_
#define _GALAGA_MISSILE_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"              // tipos espec�ficos da engine
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
// Fun��es Membro Inline
inline void Arrow::Draw()
{
    sprite->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif
