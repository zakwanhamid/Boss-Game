//Include all sprite file
#include "Spriteboss.h"
#include "Spritewarrior.h"
#include "Spritewitch.h"
#include "Spriteknight.h"
#include "Spritehealer.h"
#include <iostream>
using namespace std;

#ifndef SPRITE
#define SPRITE

class sprite
{
    int spriteId;//Declare sprite ID based from input 

    //boss object;
    boss bossObj;
    
    //warrior object
    war warObj;

    //witch object
    wit witObj;

    //knight object
    kni kniObj;

    //healer object
    hea heaObj;

    public:
    sprite(){}
    ~sprite(){}

    void setId(int i){spriteId = i;}//Set id based from integer input
    
    void Normal();
    void Attack();
    void Damaged();
    void Dead();

};

//Check ID for each function
//If correspond to the intended ID
//Execute function accordingly
void sprite::Normal()
{
    switch (spriteId)
    {
        case 0:
        bossObj.Normal();
        break;

        case 1:
        warObj.Normal();
        break;

        case 2:
        witObj.Normal();
        break;

        case 3:
        kniObj.Normal();
        break;

        case 4:
        heaObj.Normal();
        break;
        
        default:
        break;
    }
}

void sprite::Attack()
{
    switch (spriteId)
    {
        case 0:
        bossObj.Attack();
        break;

        case 1:
        warObj.Attack();
        break;

        case 2:
        witObj.Attack();
        break;

        case 3:
        kniObj.Attack();
        break;

        case 4:
        heaObj.Attack();
        break;
        
        default:
        break;
    }

}

void sprite::Damaged()
{
    switch (spriteId)
    {
        case 0:
        bossObj.Damaged();
        break;

        case 1:
        warObj.Damaged();
        break;

        case 2:
        witObj.Damaged();
        break;

        case 3:
        kniObj.Damaged();
        break;

        case 4:
        heaObj.Damaged();
        break;
        
        default:
        break;
    }

}

void sprite::Dead()
{
    switch (spriteId)
    {
        case 0:
        bossObj.Dead();
        break;

        case 1:
        warObj.Dead();
        break;

        case 2:
        witObj.Dead();
        break;

        case 3:
        kniObj.Dead();
        break;

        case 4:
        heaObj.Dead();
        break;
        
        default:
        break;
    }

}


#endif