#include <iostream>
using namespace std;

#ifndef BOSS
#define BOSS
class boss
{
    public:
    boss(){}
    ~boss(){}
    void Normal();
    void Attack();
    void Damaged();
    void Dead();

};


void boss::Normal()
{
	cout<<"                                         ___                              ___         " << endl;
	cout<<"                                        /   7                            /   7        " << endl;
	cout<<"                                       /__   |      |7          /|      |   __7       " << endl;
	cout<<"                                         /  /       | 7        / |       7  7         " << endl;
	cout<<"                                         |  |       |  7______/  |       |  |         " << endl;
	cout<<"                                          7  7      /             7      /  /         " << endl;
	cout<<"                                           7  7__  /  /7      /7   7  __/  /          " << endl;
	cout<<"                                            7__  7/  |  7    /  |   7/  __/           " << endl;
	cout<<"                                               7     |   7  /   |      /              " << endl;
	cout<<"                                    /7    /7    /     7__/  7__/      7   /7    /7    " << endl;
	cout<<"                                   /  7__/  7 _|                      |__/  7__/  7   " << endl;
	cout<<"                                  / /7____/7____  |7______________/|  ____/7____/7 7  " << endl;
	cout<<"                                  7/           |  |  7/7/7/7/7/7/  |  |           7/  " << endl;
	cout<<"                                                7  7               /  /               " << endl;
	cout<<"                                              _/    7             /   7_              " << endl;
	cout<<"                                            _/   /7  7/7/7/7/7/7_/  7   7    7        " << endl;
	cout<<"                                         __/   _/  7              /  7_  7__/ 7       " << endl;             
	cout<<"                                        /   __/     |            |     7_     /       " << endl;
	cout<<"                                        7  /        |    |  |    |       7___/        " << endl;
	cout<<"                                         7/         |    |  |    |                    " << endl;
	cout<<"                                                    |    |  |    |                    " << endl;
	cout<<"                                                    /    /  /    /                    " << endl;
	cout<<"                                                   <____/  <____/                     " << endl;
	cout<<"                                                                                      " << endl;
}

void boss::Attack()
{
	cout<<"                                         ___                              ___         " << endl;
	cout<<"                                        /   7             !!!            /   7        " << endl;
	cout<<"                                       /__   |      |7          /|      |   __7       " << endl;
	cout<<"                                         /  /       | 7        / |       7  7         " << endl;
	cout<<"                                         |  |       |  7______/  |       |  |         " << endl;
	cout<<"                                          7  7      /             7      /  /         " << endl;
	cout<<"                                           7  7__  /  /7      /7   7  __/  /          " << endl;
	cout<<"                                      !!!   7__  7/  |  7    /  |   7/  __/      !!!  " << endl;
	cout<<"                                               7     |   7  /   |      /              " << endl;
	cout<<"                                    /7    /7    /     7__/  7__/      7   /7    /7    " << endl;
	cout<<"                                   /  7__/  7 _|                      |__/  7__/  7   " << endl;
	cout<<"                                  / /7____/7____  |7______________/|  ____/7____/7 7  " << endl;
	cout<<"                                  7/           |  |  7/7/7/7/7/7/  |  |           7/  " << endl;
	cout<<"                                                7  7               /  /               " << endl;
	cout<<"                                              _/    7             /   7_       !!!    " << endl;
	cout<<"                                     !!!    _/   /7  7/7/7/7/7/7_/  7   7    7        " << endl;
	cout<<"                                         __/   _/  7              /  7_  7__/ 7       " << endl;             
	cout<<"                                        /   __/     |            |     7_     /       " << endl;
	cout<<"                                        7  /        |    |  |    |       7___/        " << endl;
	cout<<"                                         7/         |    |  |    |                    " << endl;
	cout<<"                                                !!! |    |  |    |     !!!            " << endl;
	cout<<"                                                    /    /  /    /                    " << endl;
	cout<<"                                                   <____/  <____/                     " << endl;
	cout<<"                                                                                      " << endl;
}

void boss::Damaged()
{
	cout<<"                                         ___                              ___         " << endl;
	cout<<"                                        /   7                            /   7        " << endl;
	cout<<"                                       /__   |      |7          /|      |   __7       " << endl;
	cout<<"                                         /  /       | 7   $$   / |       7  7         " << endl;
	cout<<"                                         |  |       |  7______/  |       |  |         " << endl;
	cout<<"                                          7  7   $$ /  _          7  $$  /  /         " << endl;
	cout<<"                                           7  7__  /  / \\     __   7  __/  /         " << endl;
	cout<<"                                            7__  7/  |   |   /  \\  7/  __/           " << endl;
	cout<<"                                        $$$    7     |$$ |  | $$ |     /  $$$         " << endl;
	cout<<"                                    /7    /7    /    \\__/    \\__/      7   /7    /7 " << endl;
	cout<<"                                   /  7__/  7 _|                       |__/  7__/  7  " << endl;
	cout<<"                                  / /7____/7____                       ____/7____/7 7 " << endl;
	cout<<"                                  7/     $$$   |     /\\/\\/\\/\\/\\        | $$$       7/ " << endl;
	cout<<"                                                7   (          )     /                   " << endl;
	cout<<"                                           $$$_/     \\/\\/\\/\\/\\/      7_              " << endl;
	cout<<"                                            _/   /7                 7   7    7        " << endl;
	cout<<"                                         __/   _/  7              /  7_  7__/ 7       " << endl;             
	cout<<"                                        /   __/     |            |     7_     /       " << endl;
	cout<<"                                        7  /        |    |  |    |       7___/        " << endl;
	cout<<"                                         7/         |    |  |    |                    " << endl;
	cout<<"                                                    |    |  |    |                    " << endl;
	cout<<"                                                    /    /  /    /                    " << endl;
	cout<<"                                                   <____/  <____/                     " << endl;
	cout<<"                                                                                      " << endl;
}

void boss::Dead()
{
	cout<<"                                         ___                              ___         " << endl;
	cout<<"                                        /   7                            /   7        " << endl;
	cout<<"                                       /__   |      |7          /|      |   __7       " << endl;
	cout<<"                                         /  /       | 7   RIP  / |       7  7         " << endl;
	cout<<"                                         |  |       |  7______/  |       |  |         " << endl;
	cout<<"                                          7  7   RIP/             7   RIP/  /         " << endl;
	cout<<"                                           7  7__  /   __     __   7  __/  /          " << endl;
	cout<<"                                            7__  7/   /  \\   /  \\   7/  __/         " << endl;
	cout<<"                                        RIP    7     | \\/ | | \\/ |     /  RIP       " << endl;
	cout<<"                                    /7    /7    /    | /\\ | | /\\ |     7   /7    /7 " << endl;
	cout<<"                                   /  7__/  7 _|      \\__/   \\__/      |__/  7__/  7" << endl;
	cout<<"                                  / /7____/7____                       ____/7____/7 7 " << endl;
	cout<<"                                  7/     RIP   |                       | RIP       7/ " << endl;
	cout<<"                                                7                     /               " << endl;
	cout<<"                                           RIP_/      XXXXXXXXXXX     7_              " << endl;
	cout<<"                                            _/   /7                 7   7    7        " << endl;
	cout<<"                                         __/   _/  7              /  7_  7__/ 7       " << endl;             
	cout<<"                                        /   __/     |            |     7_     /       " << endl;
	cout<<"                                        7  /        |    |  |    |       7___/        " << endl;
	cout<<"                                         7/         |    |  |    |                    " << endl;
	cout<<"                                                    |    |  |    |                    " << endl;
	cout<<"                                                    /    /  /    /                    " << endl;
	cout<<"                                                   <____/  <____/                     " << endl;
	cout<<"                                                                                      " << endl;
}

#endif