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

#include "TileSet.h"
#include "Animation.h"
// ---------------------------------------------------------------------------------

class Arrow : public Object
{
private:
    Animation* spriteAnimation;
    float vel;

public:
    Arrow(TileSet* tiles);
    ~Arrow();

    void OnCollision(Object* obj);     // resolu��o da colis�o
    void EnemyCollision(Object* obj);

    void Update();
    void Draw();
};
 
// ---------------------------------------------------------------------------------
// Fun��es Membro Inline
inline void Arrow::Draw()
{
    spriteAnimation->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif
