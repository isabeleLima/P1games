/**********************************************************************************
// Missile (C�digo Fonte)
//
// Cria��o:     21 Dez 2012
// Atualiza��o: 26 Fev 2023
// Compilador:  Visual C++ 2022
//
// Descri��o:   M�sseis do jogo Galaga
//
**********************************************************************************/

#include "Hit.h"
#include "Level1.h"
#include "Scene.h"
#include "index.h"
#include "Enemy.h"

// ---------------------------------------------------------------------------------
int a;
Hit::Hit(TileSet* tiles, int x, int y)
{

    type = ARROW;
    a = 0;
    spriteAnimation = new Animation(tiles, 0.5f, true);
    MoveTo(x, y, Layer::FRONT);
}

// ---------------------------------------------------------------------------------

Hit::~Hit()
{
    delete spriteAnimation;
}

// ---------------------------------------------------------------------------------

void Hit::Update()
{
    if (a == 3){
        Level1::scene->Delete();
    }
    else {
        a++;
    }
   
}


// ---------------------------------------------------------------------------------
