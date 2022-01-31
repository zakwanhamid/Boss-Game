#include <iostream>
#include "RPSstack.h"
#include "Sprite.h"
using namespace std;

#ifndef PLAYER
#define PLAYER

class player
{
    private:
    stack health;//Stack object
    stack mana;//Stack object

    //Private member
    int damage;
    int hit;
    bool statusbar;
    string name;
    int id;

    sprite spriteObj;//Sprite object

    public:
    player();
    ~player(){}

    //Set functions
    void setName(string n){name = n;}
    void setHealth(int n){health.~stack(); for (int i = 0; i < n; i++) {health.push(statusbar);}}
    void setId(int i){id = i; spriteObj.setId(i);}

    //Get functions
    string getName(){return name;}
    int getHit(){return hit;}
    int getId(){return id;}
    int getHealth(){return health.getLength();}
    int getMana(){return mana.getLength();}
    int getDamage(){return damage;}

    //Minus functions
    void minusHealth(int n){for (int i = 0; i < n; i++) {health.pop();}}
    void minusDamage(){damage--;}

    //Reset functions
    void resetMana(){mana.pop(); mana.pop();}
    void resetDamage(){damage = 0;}


    //Plus functions
    void plusHealth(){health.push(statusbar);}
    void plusMana(){mana.push(statusbar);}
    void plusMana(int n){for (int i = 0; i < n; i++) {mana.push(statusbar);}}
    void plusDamage(){damage++;}
    void plusHit(int n){hit+= n;}

    //Print sprite functions
    void printNormal(){spriteObj.Normal();}
    void printAttack(){spriteObj.Attack();}
    void printDamaged(){spriteObj.Damaged();}
    void printDead(){spriteObj.Dead();}

    
};

//Set constructor
player::player()
{
    damage = 1;
    hit = 0;
    statusbar = true;
    name = "";
    id = 0;

    int healthSize = 5;
    
    for (int i = 0; i < healthSize; i++)
    {
        health.push(statusbar);
    }
    
}

#endif