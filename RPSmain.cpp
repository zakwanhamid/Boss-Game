//--------------------------------------------------------------------------------
//PROGRAMMERS' NAME: MOHAMMAD DANIAL HAKIM BIN ZOL, MOHAMAD ZAKWAN BIN ABD HAMID
//MATRIC NUMBER: 152622, 153180 
//Date: 18/06/2021
//--------------------------------------------------------------------------------

//Include header built in library
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

//Include header file for suitable system
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

//Include selfmade library
#include "RPSgamelist.h"
#include "RPSplayer.h"
#include "SpriteRPS.h"

//Declare pause function
void pressToContinue();

//Declare input validation function
int inputVal(char);

//Declare function to check if all player alive 
bool isAlive(player*, player*);

//Declare get player input function
void getPlayerInfo(player*, int, list<string>&, bool&);

//Declare other game function
void isHit(player& , player& , int& );
bool compare(int , int );
void setHighscore(player* , player& , int, int&);
void mvpChecker(player* , player& , int, int);

//Declare print function
void printUpperscore(int );
void printStatusbar(int, int);
void printStatusbar(int );
void printIsHit(player& , bool&);
void printIsHit(player& , player& , int& );
void printBlessing(player& playerObj);
void printPlayerStatus(player*, int);
void printGameOverLost();
void printGameOverWin();

//Declare main game function
void isGame (player*, player&, int&, list<string>&, list<string>&, RPSsprite&, int, bool&);


//Start
int main() 
{
    //System variable
    string name = ""; 
    int highscore = 0; 
    RPSsprite rpsObj; //Sprite Object
    bool isGp2 = false; //Check if group 2

    //Set moves linked list
    list<string> moves;
    moves.append("Rock");
    moves.append("Paper");
    moves.append("Scissors");

    //Set player linked list
    list<string> heroes;
    heroes.append("Warrior");
    heroes.append("Witch");
    heroes.append("Knight");
    heroes.append("Healer");

    
    //Input variable
    char userInput = ' ';
    int userGuess = 0;
    bool inputPoint = false;

    //Number of players per group
    const int numPlayer = 2;

    //Boss declaration
    player boss;
    boss.setName("Zodiac Killer");
    boss.setId(0);
    boss.setHealth(10);//Set boss health

    //Hero declaration
    player gp1[numPlayer];//Group 1
    player gp2[numPlayer];//Group 2
    

    //Marks group
    int gp1Mark = 0;
    int gp2Mark = 0;

    //Get player info
    getPlayerInfo(gp1, numPlayer, heroes, isGp2);
    getPlayerInfo(gp2, numPlayer, heroes,isGp2);

    isGp2 = false; //Set is group 2 false for the first time  

    //Set randomize computer input
    int compGuess = 0;
    std::srand (time(NULL));

    //Start game screen
    std::system("CLS"); 
    std::cout << "                                           -----------------------------"                  << endl;
    std::cout << "                                           | RPS ROLEPLAYING ADVENTURE |"                 << endl;
    std::cout << "                                           -----------------------------"                  << endl << endl;

    std::cout << "                                                  Welcome! Heroes... "                   << endl;
    std::cout << "                                   Salem town is under attack and we need your help.  "   << endl;
    std::cout << "                                                         . "                             << endl;
    std::cout << "                                        You will be up against Zodiac Killer"             << endl;
    std::cout << "                                 Which is one of the most fearsome mythical beast here"   << endl;
    std::cout << "                                                         . "                             << endl;
    std::cout << "                                        You will have this list set of moves: "           << endl;
    std::cout << "                                       ---------------------------------------"           << endl;
    std::cout << "                                       |         (1) for Rock                |"           << endl;      
    std::cout << "                                       |         (2) for Paper               |"           << endl;
    std::cout << "                                       |         (3) for Scissors            |"           << endl;
    std::cout << "                                       ---------------------------------------"           << endl;
    std::cout << "                                                         . "                             << endl;
    std::cout << "                                         Defeat the beast and claim victory!"             << endl;
    std::cout << "                                     All the best in your journey, adventurer."           << endl;
    std::cout << "                                            May the the 4th be with you."                 << endl << endl;

    pressToContinue();
    std::system("CLS");
    
    bool knightBlock = false; //Declare in game variable false for the first time

    //Execute main game function until
    //Boss is dead or
    //All player is dead
    do
    {
        isGame(gp1, boss, gp1Mark, moves, heroes, rpsObj, numPlayer, knightBlock);
        if(!boss.getHealth())
        break;
        isGame(gp2, boss, gp2Mark, moves, heroes, rpsObj, numPlayer, knightBlock);
    }
    while (isAlive(gp1, gp2) && boss.getHealth());


    //If boss dead 
    if (!boss.getHealth())
    {
       std::cout << "\n\t\t\t\tYou'd beaten the boss, Hero. Claim your victory heroes!" << endl << endl;;

        //Print if player death or alive
        std::cout << "\t\t\t\t\t\t   Player Status: " << endl;
        std::cout <<"\t\t\t\t\t\t   "; printUpperscore(14); std::cout << endl;
        printPlayerStatus(gp1, numPlayer);
        printPlayerStatus(gp2, numPlayer);
        std::cout << endl << endl;

        pressToContinue();
        std::system("CLS");

        //set highscore
        setHighscore(gp1, boss, numPlayer, highscore);
        setHighscore(gp2, boss, numPlayer, highscore);
        
        //Print MVP
        std::cout << endl;
        std::cout << "\t\t\t\t\t\t  Highest score: " << highscore << endl <<endl;
        std::cout << "               \t\t\t\t      -----------------------"                  << endl;
        std::cout << "               \t\t\t\t      |         MVP:        |"                   << endl;
        std::cout << "               \t\t\t\t      -----------------------"                  << endl;
        mvpChecker(gp1, boss, numPlayer, highscore);
        mvpChecker(gp2, boss, numPlayer, highscore);
        std::cout << endl << endl;
        
        std::cout << "\t\t\t\t\t\t    Group Score: " << endl;
        std::cout <<"\t\t\t\t\t\t "; printUpperscore(16); std::cout << endl;
        std::cout << "\t\t\t\t\t\t     Group 1: " << gp1Mark << endl;
        std::cout << "\t\t\t\t\t\t     Group 2: " << gp2Mark << endl << endl;

        std::cout << endl;
        
        //Check winning group based on group's mark
        if (gp1Mark > gp2Mark)
        {
            std::cout << "\t\t\t\t   Group 1 score higher. Group 1 winning, Congrats!" << endl;
        }
        else if (gp1Mark < gp2Mark)
        {
            std::cout << "\t\t\t\t   Group 2 score higher. Group 2 winning, Congrats!" << endl;       
        }
        else
        {
            std::cout << "\t\t\t\t\t     Both group score the same.\n\t\t\t\t   No clear winner as you're both awesome, congrats!" << endl;
        }
         
        pressToContinue();
        std::system("CLS");

        //Display winning screen
        std::cout << "\n\t\t\t\t\t\t    Reign supremity. \n\t\t\t\t\t          Adventurers has won!" << endl << endl;;
        printGameOverWin();    
    }

    //If all player died
    else
    {   
        //Display lost screen
        std::cout << "\n\n\n\n\n\t\t\t\t\t    All heroes has fallen" << endl << endl;
        pressToContinue();
        std::system("CLS");
        std::cout << "\n\t\t\t\t\t       Fallen Warriors. \n\t\t\t\t\tYour souls has been devoured!" << endl << endl;;
        printGameOverLost();
    }
        
        
    return 0;
}


void pressToContinue() //System pause
{
    std::cout << "                                         (Press ENTER to continue...)";
    getchar();
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    cin.clear();  
}

int inputVal(char input) //Input validation
{
    int guess;
    while (input != '1' && input != '2' && input != '3')
    {
        //Clear buffer
        std::cin.ignore();
        std::cin.clear();

        //Prompt error
        std::cout << "\t\t\t\t  That's not a correct move, please try again: ";
        std::cin >> input;
        
    }
    guess = input - '0';
    return guess;
}

bool isAlive(player* gp1, player* gp2)//Check is all player alive 
{
    bool allPlayerAlive = false;

        for (int i = 0; i < 2; i++)
        {
            allPlayerAlive = allPlayerAlive || gp1[i].getHealth();
            allPlayerAlive = allPlayerAlive || gp2[i].getHealth();
        }
        
        return allPlayerAlive;
}


void getPlayerInfo(player* gpObj, int n, list<string>& herolist, bool& checkGp2)
{
    for (int i = 0; i < n; i++)
    {
        //Display input screen 
        std::system("CLS");
        std::cout << "                                           -----------------------------"                 << endl << flush;
        std::cout << "                                           | RPS ROLEPLAYING ADVENTURE |"                 << endl << flush;
        std::cout << "                                           -----------------------------"                 << endl << endl;

        std::cout << "                                      Brave warriors, please enter your name: "           << endl << endl;
        string name;

        //check group to display message accordingly
        if (!checkGp2)
        std::cout << "                                                      Group 1: "                          << endl;
        else
        std::cout << "                                                      Group 2: "                          << endl;

        std::cout << "                                                     "; printUpperscore(9); std::cout     << endl;

        if (!checkGp2)
        gpObj[i].setId(i + 1);
        else
        gpObj[i].setId(i + 3);

        //prompt input
        std::cout << "                                               Enter player " << gpObj[i].getId() << " name: ";
        std::cin >> name;
        gpObj[i].setName(name);

        //Display roles
        gpObj[i].printNormal();
        std::cout << endl << "                                                   Names: " << gpObj[i].getName() << endl;
        std::cout << "                                                   Roles: " << herolist.get(gpObj[i].getId()) << endl << endl;

        pressToContinue();
    }

    checkGp2 = true;
}

bool compare(int guess, int compGuess) //Compare player's moves with boss's moves
{
    bool stat = false;

    if (guess == 1)
    {
        if (compGuess == 3)
        stat = true;
    }
    else if (guess == 2)
    {
        if (compGuess == 1)
        stat = true;
    }
    else
    {
        if (compGuess == 2)
        stat = true;
    }

    return stat;
}

void isHit(player& playerObj, player& compObj, int& gpMark)//If player lands hit

{
    compObj.minusHealth(playerObj.getDamage());
    playerObj.plusHit(playerObj.getDamage());
    gpMark += playerObj.getDamage();
}

void setHighscore(player* gpObj, player& compObj, int numPlay, int& score)//Set highscore based on player score
{
    for (int i = 0; i < numPlay; i++)
        {
            if (score == 0)
            score = gpObj[i].getHit();
            
            if(score < gpObj[i].getHit())
            score = gpObj[i].getHit();
        }
}

void mvpChecker(player* gpObj, player& compObj, int numPlay, int score) //Check highest score among player
{
    for (int i = 0; i < numPlay; i++)
        {
            if (gpObj[i].getHit() == score)
            cout << "               \t\t\t\t\t    => " << gpObj[i].getName() << endl;
        }
}


void printUpperscore(int n)//Print upperscore for a number of time
{
    for (int i = 0; i < n; i++)
    {
        cout << char(196);
    }
}

void printStatusbar(int n) //Print health and mana statusbar for boss
{
    std::cout << "\t\t\t\t\t ---------------------------------" << endl;
    std::cout << "\t\t\t\t\t   Health: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << char(219);
    }
    
    char m = char(236);
    std::cout << "\n\t\t\t\t\t   Mana:   " << m << endl;
    std::cout << "\t\t\t\t\t ---------------------------------" << endl;
}

void printStatusbar(int n, int m)//Print health and mana statusbar for player
{
    std::cout << "\t\t\t\t\t ---------------------------------" << endl;
    std::cout << "\t\t\t\t\t   Health: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << char(219);
    }

    std::cout << "\n\t\t\t\t\t   Mana:   ";
    for (int i = 0; i < m; i++)
    {
        std::cout << char(219);
    }
    std::cout << "\n\t\t\t\t\t ---------------------------------" << endl;
}


void printIsHit(player& Obj, bool& isKnightActive)//Changing visual when player is hit
{
    if (isKnightActive && Obj.getId() == 3)//If player is knight and shield is on 
    {
        
        std::cout << "\t\t\t\t\t  Knight's block activated!\n\t\t\t\t   You're left unscatch from the battle." << endl;

        Sleep(1500);
        std::system("CLS");

        std::cout << endl << endl << endl << endl;
        Obj.printAttack();
        printStatusbar(Obj.getHealth(), Obj.getMana());
        Sleep(800);
        std::system("CLS");

        std::system("Color 1");
        std::cout << endl << endl << endl << endl;
        Obj.printNormal();
        printStatusbar(Obj.getHealth(), Obj.getMana());
        Sleep(800);
        std::system("CLS");

        std::system("Color 07");
        std::cout << endl << endl << endl << endl;
        Obj.printDamaged();
        printStatusbar(Obj.getHealth(), Obj.getMana());

        isKnightActive = false;
    }
    else//All other player
    {
        std::cout << "\n\n\t\t\t\t      Watch your back, incoming attack!" << endl;

        Sleep(1500);
        std::system("CLS");
        
        std::cout << endl << endl << endl << endl;
        Obj.printNormal();
        printStatusbar(Obj.getHealth(), Obj.getMana());
        Sleep(800);
        std::system("CLS");

        Obj.minusHealth(Obj.getDamage());
        std::system("Color 4");
        std::cout << endl << endl << endl << endl;
        Obj.printDamaged();
        printStatusbar(Obj.getHealth(), Obj.getMana());
        Sleep(800);
        std::system("CLS");

        std::system("Color 07");
        if (Obj.getHealth())
        {
            std::cout << endl << endl << endl << endl;
            Obj.printDamaged();
        }
                  
        else
        {
            std::cout << endl << endl << endl << endl;
            Obj.printDead();
        }

        printStatusbar(Obj.getHealth(), Obj.getMana());
  
    }
}

void printIsHit(player& playerObj, player& compObj, int& mark)//Changing visual when boss is hit
{
    Sleep(1500);
    std::system("CLS");

    compObj.printNormal();
    printStatusbar(compObj.getHealth());
    Sleep(800);
    std::system("CLS");

    isHit(playerObj, compObj, mark);
    std::system("Color 4");
    compObj.printDamaged();
    printStatusbar(compObj.getHealth());
    Sleep(800);
    std::system("CLS");

    std::system("Color 07");
    if (compObj.getHealth())
    {
        compObj.printDamaged(); 
    }
             
    else
    {
        compObj.printDead();
    }
        
    printStatusbar(compObj.getHealth());
}


void printPlayerStatus(player* gpObj, int n)//Print player alive status
{
            for (int i = 0; i < n; i++)
        {
            if (!gpObj[i].getHealth())
                std::cout << "\t\t\t\t\t" << gpObj[i].getName() << "\thas FALLEN. Last Score: " << gpObj[i].getHit() << endl;
            else
                std::cout << "\t\t\t\t\t" <<  gpObj[i].getName()  << "\tis doing great! Score: " << gpObj[i].getHit() << endl;
        }
}


void printGameOverLost()//Display lost screen
{
        char a = char(197);
        char b = char(219);
        char c = char(223);
        char d = char(220);
        char e = char(196);

        std::cout <<"\t\t\t\t     "<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<endl;
        std::cout <<"\t\t\t\t     "<<b<<b<<b<<c<<c<<c<<b<<b<<a<<b<<b<<b<<c<<c<<c<<b<<b<<b<<a<<b<<b<<b<<c<<b<<d<<b<<c<<b<<b<<b<<a<<b<<b<<c<<c<<c<<endl;
        std::cout <<"\t\t\t\t     "<<b<<b<<a<<a<<a<<a<<b<<b<<a<<b<<b<<a<<a<<a<<a<<a<<b<<b<<a<<b<<b<<a<<a<<a<<b<<a<<a<<a<<b<<b<<a<<b<<b<<a<<a<<a<<endl;
        std::cout <<"\t\t\t\t     "<<b<<b<<a<<a<<a<<d<<d<<d<<a<<b<<b<<d<<d<<d<<d<<d<<b<<b<<a<<b<<b<<a<<a<<a<<c<<a<<a<<a<<b<<b<<a<<b<<b<<c<<c<<c<<endl;
        std::cout <<"\t\t\t\t     "<<b<<b<<a<<a<<a<<a<<b<<b<<a<<b<<b<<a<<a<<a<<a<<a<<b<<b<<a<<b<<b<<a<<a<<a<<a<<a<<a<<a<<b<<b<<a<<b<<b<<a<<a<<a<<endl;
        std::cout <<"\t\t\t\t     "<<b<<b<<b<<d<<d<<d<<b<<b<<a<<b<<b<<a<<a<<a<<a<<a<<b<<b<<a<<b<<b<<a<<a<<a<<a<<a<<a<<a<<b<<b<<a<<b<<b<<d<<d<<d<<endl;
        std::cout <<"\t\t\t\t     "<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<endl;
        std::cout <<"\t\t\t\t     "<<b<<b<<b<<c<<c<<c<<b<<b<<b<<a<<c<<b<<b<<b<<a<<a<<b<<b<<c<<a<<b<<b<<c<<c<<c<<a<<b<<b<<c<<c<<c<<c<<b<<b<<d<<a<<endl;
        std::cout <<"\t\t\t\t     "<<b<<b<<a<<a<<a<<a<<a<<b<<b<<a<<a<<a<<b<<b<<a<<a<<b<<b<<a<<a<<b<<b<<a<<a<<a<<a<<b<<b<<a<<a<<a<<a<<a<<b<<b<<a<<endl;
        std::cout <<"\t\t\t\t     "<<b<<b<<a<<a<<a<<a<<a<<b<<b<<a<<a<<a<<b<<b<<a<<a<<b<<b<<a<<a<<b<<b<<c<<c<<c<<a<<b<<b<<d<<d<<d<<d<<d<<c<<c<<a<<endl;
        std::cout <<"\t\t\t\t     "<<b<<b<<a<<a<<a<<a<<a<<b<<b<<a<<a<<a<<b<<b<<a<<a<<b<<c<<a<<a<<b<<b<<a<<a<<a<<a<<b<<b<<a<<a<<a<<a<<a<<b<<b<<a<<endl;
        std::cout <<"\t\t\t\t     "<<b<<b<<b<<d<<d<<d<<b<<b<<b<<a<<a<<a<<e<<c<<b<<c<<a<<a<<e<<a<<b<<b<<d<<d<<d<<a<<b<<b<<a<<a<<a<<a<<a<<b<<b<<d<<endl;
        std::cout <<"\t\t\t\t     "<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<endl;
        std::cout <<"\t\t\t\t     "<<a<<a<<a<<a<<a<<a<<a<<a<<b<<b<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<b<<b<<a<<a<<a<<a<<a<<a<<a<<a<<a<<endl;
        std::cout <<"\t\t\t\t     "<<a<<a<<a<<a<<a<<a<<b<<b<<b<<b<<d<<a<<a<<a<<d<<d<<d<<d<<d<<d<<d<<a<<a<<a<<d<<b<<b<<b<<b<<a<<a<<a<<a<<a<<a<<a<<endl;
        std::cout <<"\t\t\t\t     "<<a<<a<<a<<a<<a<<a<<a<<a<<a<<c<<c<<b<<d<<b<<b<<b<<b<<b<<b<<b<<b<<b<<d<<b<<c<<c<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<endl;
        std::cout <<"\t\t\t\t     "<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<endl;
        std::cout <<"\t\t\t\t     "<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<b<<b<<c<<c<<c<<b<<b<<b<<c<<c<<c<<b<<b<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<endl;
        std::cout <<"\t\t\t\t     "<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<b<<b<<a<<a<<a<<b<<b<<b<<a<<a<<a<<b<<b<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<endl;
        std::cout <<"\t\t\t\t     "<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<b<<b<<b<<b<<b<<c<<d<<c<<b<<b<<b<<b<<b<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<endl;
        std::cout <<"\t\t\t\t     "<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<endl;
        std::cout <<"\t\t\t\t     "<<a<<a<<a<<a<<a<<a<<a<<a<<d<<d<<d<<b<<b<<a<<a<<b<<c<<b<<c<<b<<a<<a<<b<<b<<d<<d<<d<<a<<a<<a<<a<<a<<a<<a<<a<<a<<endl;
        std::cout <<"\t\t\t\t     "<<a<<a<<a<<a<<a<<a<<a<<a<<c<<c<<b<<b<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<b<<b<<c<<c<<a<<a<<a<<a<<a<<a<<a<<a<<a<<endl;
        std::cout <<"\t\t\t\t     "<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<c<<c<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<c<<c<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<endl;
        std::cout <<"\t\t\t\t     "<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<endl;
}

void printGameOverWin()//Display win screen
{
        char a = char(197);
        char b = char(219);
        char c = char(223);
        char d = char(220);
        char e = char(196);
        std::cout<<"\t\t\t\t\t  "<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<endl;
        std::cout<<"\t\t\t\t\t  "<<b<<b<<b<<c<<c<<c<<b<<b<<a<<b<<b<<b<<c<<c<<c<<b<<b<<b<<a<<b<<b<<b<<c<<b<<d<<b<<c<<b<<b<<b<<a<<b<<b<<c<<c<<c<<endl;
        std::cout<<"\t\t\t\t\t  "<<b<<b<<a<<a<<a<<a<<b<<b<<a<<b<<b<<a<<a<<a<<a<<a<<b<<b<<a<<b<<b<<a<<a<<a<<b<<a<<a<<a<<b<<b<<a<<b<<b<<a<<a<<a<<endl;
        std::cout<<"\t\t\t\t\t  "<<b<<b<<a<<a<<a<<d<<d<<d<<a<<b<<b<<d<<d<<d<<d<<d<<b<<b<<a<<b<<b<<a<<a<<a<<c<<a<<a<<a<<b<<b<<a<<b<<b<<c<<c<<c<<endl;
        std::cout<<"\t\t\t\t\t  "<<b<<b<<a<<a<<a<<a<<b<<b<<a<<b<<b<<a<<a<<a<<a<<a<<b<<b<<a<<b<<b<<a<<a<<a<<a<<a<<a<<a<<b<<b<<a<<b<<b<<a<<a<<a<<endl;
        std::cout<<"\t\t\t\t\t  "<<b<<b<<b<<d<<d<<d<<b<<b<<a<<b<<b<<a<<a<<a<<a<<a<<b<<b<<a<<b<<b<<a<<a<<a<<a<<a<<a<<a<<b<<b<<a<<b<<b<<d<<d<<d<<endl;
        std::cout<<"\t\t\t\t\t  "<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<endl;
        std::cout<<"\t\t\t\t\t  "<<b<<b<<b<<c<<c<<c<<b<<b<<b<<a<<c<<b<<b<<b<<a<<a<<b<<b<<c<<a<<b<<b<<c<<c<<c<<a<<b<<b<<c<<c<<c<<c<<b<<b<<d<<a<<endl;
        std::cout<<"\t\t\t\t\t  "<<b<<b<<a<<a<<a<<a<<a<<b<<b<<a<<a<<a<<b<<b<<a<<a<<b<<b<<a<<a<<b<<b<<a<<a<<a<<a<<b<<b<<a<<a<<a<<a<<a<<b<<b<<a<<endl;
        std::cout<<"\t\t\t\t\t  "<<b<<b<<a<<a<<a<<a<<a<<b<<b<<a<<a<<a<<b<<b<<a<<a<<b<<b<<a<<a<<b<<b<<c<<c<<c<<a<<b<<b<<d<<d<<d<<d<<d<<c<<c<<a<<endl;
        std::cout<<"\t\t\t\t\t  "<<b<<b<<a<<a<<a<<a<<a<<b<<b<<a<<a<<a<<b<<b<<a<<a<<b<<c<<a<<a<<b<<b<<a<<a<<a<<a<<b<<b<<a<<a<<a<<a<<a<<b<<b<<a<<endl;
        std::cout<<"\t\t\t\t\t  "<<b<<b<<b<<d<<d<<d<<b<<b<<b<<a<<a<<a<<e<<c<<b<<c<<a<<a<<e<<a<<b<<b<<d<<d<<d<<a<<b<<b<<a<<a<<a<<a<<a<<b<<b<<d<<endl;
        std::cout<<"\t\t\t\t\t  "<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<endl;
        std::cout<<"\t\t\t\t\t  "<<a<<a<<a<<a<<a<<a<<a<<a<<d<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<d<<a<<a<<a<<a<<a<<a<<a<<a<<a<<endl;
        std::cout<<"\t\t\t\t\t  "<<a<<a<<a<<a<<a<<a<<d<<c<<c<<c<<d<<a<<a<<a<<d<<d<<d<<d<<d<<d<<d<<a<<a<<a<<d<<c<<c<<c<<d<<a<<a<<a<<a<<a<<a<<a<<endl;
        std::cout<<"\t\t\t\t\t  "<<a<<a<<a<<a<<a<<b<<a<<a<<a<<a<<c<<b<<d<<b<<c<<c<<c<<c<<c<<c<<c<<b<<d<<b<<c<<a<<a<<a<<a<<b<<a<<a<<a<<a<<a<<a<<endl;
        std::cout<<"\t\t\t\t\t  "<<a<<a<<a<<a<<a<<b<<a<<a<<a<<a<<a<<b<<b<<d<<a<<a<<a<<a<<a<<a<<a<<d<<b<<b<<a<<a<<a<<a<<a<<b<<a<<a<<a<<a<<a<<a<<endl;
        std::cout<<"\t\t\t\t\t  "<<a<<a<<a<<a<<a<<c<<d<<a<<a<<a<<a<<b<<b<<b<<b<<d<<d<<d<<d<<d<<b<<b<<b<<b<<a<<a<<a<<a<<d<<c<<a<<a<<a<<a<<a<<a<<endl;
        std::cout<<"\t\t\t\t\t  "<<a<<a<<a<<a<<a<<a<<a<<c<<c<<c<<c<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<c<<c<<c<<c<<a<<a<<a<<a<<a<<a<<a<<a<<endl;
        std::cout<<"\t\t\t\t\t  "<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<b<<b<<b<<b<<b<<c<<d<<c<<b<<b<<b<<b<<b<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<endl;
        std::cout<<"\t\t\t\t\t  "<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<b<<b<<b<<b<<b<<d<<b<<b<<b<<b<<b<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<endl;
        std::cout<<"\t\t\t\t\t  "<<a<<a<<a<<a<<a<<a<<c<<d<<a<<a<<a<<a<<a<<a<<a<<b<<b<<b<<b<<b<<a<<a<<a<<a<<a<<a<<a<<d<<c<<a<<a<<a<<a<<a<<a<<a<<endl;
        std::cout<<"\t\t\t\t\t  "<<a<<a<<a<<a<<a<<a<<a<<c<<c<<c<<b<<b<<a<<a<<a<<a<<c<<b<<c<<a<<a<<a<<a<<b<<b<<c<<c<<c<<a<<a<<a<<a<<a<<a<<a<<a<<endl;
        std::cout<<"\t\t\t\t\t  "<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<c<<c<<a<<a<<a<<a<<a<<b<<a<<a<<a<<a<<a<<c<<c<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<endl;
        std::cout<<"\t\t\t\t\t  "<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<d<<d<<d<<b<<b<<b<<b<<b<<d<<d<<d<<d<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<endl;

}


void isGame(player* gpObj, player& compObj, int& gpMark, list<string>& moves, list<string>& heroes, RPSsprite& spriteObj, int numPlay, bool& knightBlock)
{
    //Function variable
    char userInput = ' ';
    int userGuess = 0;
    int compGuess = 0;

    for (int  i = 0; i < numPlay; i++)//For number of players
    {
        //Print loading screen for each player
        std::system("CLS");
        std::cout << endl << endl;
        std::cout << "\t\t\t\t\t\t      Player " << gpObj[i].getId() << ": " << endl;
        std::cout <<"\t\t\t\t\t\t   "; printUpperscore(14); std::cout << endl;
        std::cout << "\t\t\t\t\t\t       " << "*****" << endl << endl; 
        gpObj[i].printAttack(); std::cout << endl << endl;
        printStatusbar(gpObj[i].getHealth(),gpObj[i].getMana()); std::cout << endl << endl;
        std::cout << "\t\t\t\t\t\t   (LOADING...)" << endl;
        Sleep(1500);
        std::system("CLS");

        //If player is deadm display dead sprite
        if (!gpObj[i].getHealth())
        {
            gpObj[i].printDead();
            std::cout << "\n\t\t\t\t\t    " << "The player is already dead.\n\t\t\t\t\t    Please continue the legacy." << endl << endl << endl << endl;
            pressToContinue();
            std::system("CLS");
            continue;
        }
        
            else//if player is alive
            {

                //If mana greater of equal to 2
                //Invoke special ability
                if (gpObj[i].getMana() >= 2)
                {
                    std::cout << "\n\t\t\t\t\t   You have reach your full potential.\n\t\t\t\t\t\t     4th activated. " << endl;
                    std::cout << "\n\t\t\t\t\t    " << heroes.get(gpObj[i].getId()) << "'s 4th blessing: ";
                    switch(gpObj[i].getId())
                    {
                        //Warrior special skill, +1 damage
                        case 1:
                        std::cout << "ENRAGE" << endl << endl; //Double damage
                        std::cout << "\t\t\t\t\t-----------------------------------------" << endl;
                        std::cout << "\t\t\t\t\t        Player's damage MULTIPLIED       " << endl;
                        std::cout << "\t\t\t\t\t            Player's damage + 1          " << endl;
                        std::cout << "\t\t\t\t\t-----------------------------------------" << endl;
                        gpObj[i].plusDamage();
                        break;

                        //Witch special skill, +1 health, -1 boss health
                        case 2:
                        std::cout << "LIFE MAGIC" << endl; //Lifesteal
                        std::cout << "\t\t\t\t\t-----------------------------------------" << endl;
                        std::cout << "\t\t\t\t\t      Player steals health from boss     " << endl;
                        std::cout << "\t\t\t\t\t            Player's health + 1          " << endl;
                        std::cout << "\t\t\t\t\t             Boss's health - 1           " << endl;
                        std::cout << "\t\t\t\t\t-----------------------------------------" << endl;
                        gpObj[i].plusHealth();
                        isHit(gpObj[i], compObj, gpMark);
                        break;

                        //Knight special skill, ignore -1 health when attack
                        case 3:
                        std::cout << "WHITE SHIELD" << endl; //Block attack
                        std::cout << "\t\t\t\t\t-----------------------------------------" << endl;
                        std::cout << "\t\t\t\t\t    Player negates 1 hit from the boss   " << endl;
                        std::cout << "\t\t\t\t\t            Knight's block ON            " << endl;
                        std::cout << "\t\t\t\t\t-----------------------------------------" << endl;
                        knightBlock = true;
                        break;

                        //Healer special skill, +1 health
                        case 4:
                        std::cout << "AURA" << endl; //Heal
                        std::cout << "\t\t\t\t\t-----------------------------------------" << endl;
                        std::cout << "\t\t\t\t\t               Player heals              " << endl;
                        std::cout << "\t\t\t\t\t            Player's health + 1          " << endl;
                        std::cout << "\t\t\t\t\t-----------------------------------------" << endl;
                        gpObj[i].plusHealth();

                        break;

                        default:
                        break;
                    }
                    gpObj[i].resetMana();//Reset mana back to 0

                    pressToContinue();
                    std::system("CLS");
                }
                

                //If boss had fallen from one of the heroes' special skills, end.
                if(!compObj.getHealth())
                {
                    compObj.printDead();
                    pressToContinue();
                    std::system("CLS");
                    break;
                }
                
                //Set computer random input 
                compGuess = rand() % 3 + 1;

                compObj.printNormal();
                printStatusbar(compObj.getHealth());  std::cout << endl << endl;

                //Prompr user input
                std::cout << "\t\t\t\t\t    Fight! Input your move: ";
                std::cin >> userInput;
                userGuess = inputVal(userInput);
                std::system("CLS");

                std::cout << endl << endl;

                //Check inputs, display Rock Paper Scissors sprite accordingly
                spriteObj.checkRPS(compGuess, userGuess);

                //Player wins 
                if (compare(userGuess, compGuess))
                {
                    std::cout << "\n\n\t\t\t\t\t     Commence Attack!" << endl;

                    gpObj[i].plusMana();
                    
                    printIsHit(gpObj[i], compObj, gpMark);
                }

                else
                {
                    //Player tie
                    if (userGuess == compGuess)
                    std::cout << "\n\n\t\t\t\t Your fist clashed with the boss. It's a tie!" << endl;
                    
                    //Player loss
                    else
                        {
                            printIsHit(gpObj[i], knightBlock);
                        }
                }
                
                //If boss health fallen below 0,set it back to 0
                if (!compObj.getHealth())
                compObj.setHealth(0);

                //Check if boss health has fallen into 3
                //If so, invoke combo mode
                if (compObj.getHealth() == 3)
                {
                    std::system ("PAUSE");
                    std::system("CLS");

                    //Declare combo lists object
                    list<int> playerCombo;
                    list<int> bossCombo;

                    int win = 0;//Total combo wins

                    //Display combo screen
                    std::cout << "\t\t\t\t         The boss health has fallen into 3."   << endl;
                    std::cout << "\t\t\t\t            It's combo time. Finish him!"      << endl << endl;
                    std::cout << "."                                                << endl;
                    std::cout << "\t\t\t\t                Link 3 moves as combo! "       << endl;

                    //Prompt user input for 3 times
                    for (int j = 0; j < 3; j++)
                    {
                        std::cout << "\t\t\t\t                  Input moves #" << j + 1 << ": ";
                        std::cin >> userInput;
                        userGuess = inputVal(userInput);

                        //Get player combo list
                        playerCombo.append(userGuess);

                        //Get computer combo list
                        compGuess = rand() % 3 + 1;
                        bossCombo.append(compGuess);
                        
                    }
                    std::cout << endl;

                    //Set list back to head of list
                    playerCombo.setNodeptrHead();
                    bossCombo.setNodeptrHead();

                    int keyPlayer = 0;//Player moves ID in list
                    int keyBoss = 0;//Computer moves ID in list

                    std::cout << "\t\t\t                    _____________________________" << endl;
                    std::cout << "\t\t\t                    |       Moves combo:        |" << endl;
                    std::cout << "\t\t\t                    "; printUpperscore(29); std::cout << endl;

                    //Display list of moves chosen
                    for (int j = 0; j < moves.getLength(); j++)
                    {
                        keyPlayer = playerCombo.getCurrVal();
                        std::cout << "\t\t\t                    | < " << keyPlayer << " > ";
                        std::cout << moves.get(keyPlayer) << "\t\t|" << endl;
                    }

                    std::cout << "\t\t\t                    "; printUpperscore(29); std::cout << endl << endl << endl;

                    
                    pressToContinue();
                    std::system("CLS");

                    playerCombo.setNodeptrHead();

                    //Start combo mode
                    for (int j = 0; j < moves.getLength(); j++)
                    {   
                        keyPlayer = playerCombo.getCurrVal();
                        keyBoss = bossCombo.getCurrVal();
                        std::cout << "\n\n\t\t\t                            FIGHT!!!" << endl << endl;
                        std::cout << "\n\n\t\t\t    (Combo round is automatic, please wait until the combo is over)" << endl;
                        std::cout << "\t\t\t                          [" << j+1 << "] Round: " << endl;
                        spriteObj.checkRPS(keyBoss, keyPlayer);

                        //If player win, plus damage (up to 3 max)
                        if (compare(keyPlayer, keyBoss))
                        {
                            std::cout << "\n\n\t\t\t                          Bulleyes!" << endl;
                            win++;
                        }
                        else
                        std::cout << "\n\n\t\t\t                      It's a miss, sorry!" << endl;

                        std::cout << "\n\n\t\t\t                        Total Hit: " << win << endl;

                        Sleep(1500);
                        std::system("CLS");
                    }

                    //Reset list
                    playerCombo.setNodeptrHead();
                    bossCombo.setNodeptrHead();

                    //Hit boss for the total of wins
                    for (int i = 0; i < win; i++)
                    {
                        printIsHit(gpObj[i], compObj, gpMark);
                    }

                    gpObj[i].plusMana(win);//Plus mana by the total of wins

                }
               
                gpObj[i].resetDamage(); //Reset damage to 1
                gpObj[i].plusDamage();

                pressToContinue();
                std::system("CLS");
            }

        //If boss had fallen as the result of the fight, end.
        if(!compObj.getHealth())
        break;  
    }
}
    