#include <iostream>
using namespace std;

#ifndef KNIGHT
#define KNIGHT
class kni
{
    public:
    kni(){}
    ~kni(){}
    void Normal();
    void Attack();
    void Damaged();
    void Dead();

};


void kni::Normal()
{
	cout << endl;
	cout<<"                                                          ******      " << endl;
	cout<<"                                                      ___||__ ****    " << endl;
	cout<<"                                                     /| | | |\\  **   " << endl;
	cout<<"                                                    / + + + + \\      " << endl;
	cout<<"                                                   /|_|_|_|_|_|\\     " << endl;
	cout<<"                                                  |/   _  _    \\|    " << endl;
	cout<<"                                                  |    0  0     |     " << endl;
	cout<<"                                                  |\\_____>_____/|    " << endl;
	cout<<"                                                  \\             /    " << endl;
	cout<<"                                                   \\___________/     " << endl;
}

void kni::Attack()
{
	cout << endl;
	cout<<"                                                          ******      " << endl;
	cout<<"                                                      ___||__ ****    " << endl;
	cout<<"                                                !!   /| | | |\\  **   " << endl;
	cout<<"                                                    / + + + + \\      " << endl;
	cout<<"                                                   /|_|_|_|_|_|\\ !!  " << endl;
	cout<<"                                                !!|/   \\  /    \\|   " << endl;
	cout<<"                                                  |    0  0     |     " << endl;
	cout<<"                                                  |\\_____>_____/| !! " << endl;
	cout<<"                                                  \\             /    " << endl;
	cout<<"                                               !!  \\___________/     " << endl;
}

void kni::Damaged()
{
	cout << endl;
	cout<<"                                                           ******      " << endl;
	cout<<"                                                       ___||__ ****    " << endl;
	cout<<"                                                  $   /| | | |\\  **   " << endl;
	cout<<"                                                     / + + + + \\      " << endl;
	cout<<"                                                    /|_|_|_|_|_|\\ $   " << endl;
	cout<<"                                                  $|/   /  \\    \\|   " << endl;
	cout<<"                                                   |    *  *     |     " << endl;
	cout<<"                                                   |\\_____>_____/| $  " << endl;
	cout<<"                                                   \\             /    " << endl;
	cout<<"                                                 $  \\___________/     " << endl;
}

void kni::Dead()
{
	cout << endl;
	cout<<"                                                          ******      " << endl;
	cout<<"                                                      ___||__ ****    " << endl;
	cout<<"                                                 RIP /| | | |\\  **   " << endl;
	cout<<"                                                    / + + + + \\      " << endl;
	cout<<"                                                   /|_|_|_|_|_|\\  RIP" << endl;
	cout<<"                                                  |/   _  _    \\|    " << endl;
	cout<<"                                               RIP|    X  X     |     " << endl;
	cout<<"                                                  |\\_____>_____/|    " << endl;
	cout<<"                                                  \\             / RIP" << endl;
	cout<<"                                                   \\___________/     " << endl;
}


#endif