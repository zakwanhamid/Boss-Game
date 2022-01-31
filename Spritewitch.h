#include <iostream>
using namespace std;

#ifndef WITCH
#define WITCH
class wit
{
    public:
    wit(){}
    ~wit(){}
    void Normal();
    void Attack();
    void Damaged();
    void Dead();

};


void wit::Normal()
{
	cout <<"                                                          __*        " << endl;
	cout <<"                                                         / _\\       " << endl;
	cout <<"                                                       */  \\\\|     " << endl;
	cout <<"                                                       /    \\       " << endl;
	cout <<"                                                      /______\\      " << endl;
	cout <<"                                                   * /)()()()(\\*    " << endl;
	cout <<"                                                \\__/__________\\__/" << endl;
	cout <<"                                                   *||  _  _  ||     " << endl;
	cout <<"                                                    ||  0  0  ||     " << endl;
	cout <<"                                                    ||    >   ||*    " << endl;
	cout <<"                                                   *| \\  --  / |    " << endl;
	cout <<"                                                    |  \\____/  |    " << endl;
	cout <<"                                                   *|          |*    " << endl;
}
//                                                         spacing
void wit::Attack()
{
	cout <<"                                                          __*        " << endl;
	cout <<"                                                         / _\\       " << endl;
	cout <<"                                                       */  \\\\|     " << endl;
	cout <<"                                                       /    \\       " << endl;
	cout <<"                                                      /______\\      " << endl;
	cout <<"                                                   * /)()()()(\\*    " << endl;
	cout <<"                                                 \\__/__________\\__/" << endl;
	cout <<"                                                   *||   \\/   ||    " << endl;
	cout <<"                                                    ||  0  0  ||     " << endl;
	cout <<"                                                    ||    >   ||*    " << endl;
	cout <<"                                                   *| \\   O  / |    " << endl;
	cout <<"                                                    |  \\____/  |    " << endl;
	cout <<"                                                   *|          |*    " << endl;
}

void wit::Damaged()
{
	cout <<"                                                          __*        " << endl;
	cout <<"                                                         / _\\       " << endl;
	cout <<"                                                       */  \\\\|     " << endl;
	cout <<"                                                       /    \\       " << endl;
	cout <<"                                                      /______\\      " << endl;
	cout <<"                                                   * /)()()()(\\*    " << endl;
	cout <<"                                                 \\__/__________\\__/" << endl;
	cout <<"                                                   $||  /  \\  ||$   " << endl;
	cout <<"                                                  $ ||  *  *  || $   " << endl;
	cout <<"                                                    ||    >   ||     " << endl;
	cout <<"                                                    | \\  $$  / |    " << endl;
	cout <<"                                                    |  \\____/  |    " << endl;
	cout <<"                                                    |          |     " << endl;
}

void wit::Dead()
{
	cout <<"                                                          __         " << endl;
	cout <<"                                                         / _\\ RIP   " << endl;
	cout <<"                                                        /  \\\\|     " << endl;
	cout <<"                                                       /    \\       " << endl;
	cout <<"                                                  RIP /______\\      " << endl;
	cout <<"                                                     /)()()()(\\     " << endl;
	cout <<"                                                 \\__/__________\\__/" << endl;
	cout <<"                                                    ||  /  \\  ||    " << endl;
	cout <<"                                                    ||  x  x  || RIP " << endl;
	cout <<"                                                RIP ||    >   ||     " << endl;
	cout <<"                                                    | \\   X  / |    " << endl;
	cout <<"                                                    |  \\____/  |    " << endl;
	cout <<"                                                    |          |     " << endl;
}


#endif