#include <iostream>
using namespace std;

#ifndef HEALER
#define HEALER
class hea
{
    public:
    hea(){}
    ~hea(){}
    void Normal();
    void Attack();
    void Damaged();
    void Dead();

};


void hea::Normal()
{
	cout << "                                                      *       *         " << endl;
	cout << "                                                      ########          " << endl;
	cout << "                                                   * /        \\        " << endl;
	cout << "                                                    ############ *      " << endl;
	cout << "                                                  */ |  _  _  | \\      " << endl;
	cout << "                                                   / |  0  0  | \\      " << endl;
	cout << "                                                 */  |    >   |  \\ *   " << endl;
	cout << "                                                  /   \\  --  /   \\    " << endl;
	cout << "                                                 /_____\\____/_____\\ * " << endl;
	cout << "                                                        |  |            " << endl;
}

void hea::Attack()
{
	cout << "                                                            !!          " << endl;
	cout << "                                                  !!  ########          " << endl;
	cout << "                                                     /        \\ !!     " << endl;
	cout << "                                                    ############        " << endl;
	cout << "                                               !!  / |  \\  /  | \\     " << endl;
	cout << "                                                   / |  0  0  | \\      " << endl;
	cout << "                                                !!/  |    >   |  \\     " << endl;
	cout << "                                                  /   \\  O   /   \\  !!" << endl;
	cout << "                                                 /_____\\____/_____\\   " << endl;
	cout << "                                                        |  |            " << endl;
}

void hea::Damaged()
{
	cout << "                                                                        " << endl;
	cout << "                                                    $ ########          " << endl;
	cout << "                                                     /        \\$       " << endl;
	cout << "                                                 $  ############        " << endl;
	cout << "                                                   / |  /  \\  | \\     " << endl;
	cout << "                                                  $/ |  *  *  | \\      " << endl;
	cout << "                                                  /  |    >   |  \\ $   " << endl;
	cout << "                                                  /   \\  $$  /   \\    " << endl;
	cout << "                                                 /_____\\____/_____\\   " << endl;
	cout << "                                                        |  |            " << endl;
}

void hea::Dead()
{
	cout << "                                                                        " << endl;
	cout << "                                                      ########  RIP     " << endl;
	cout << "                                                  RIP/        \\        " << endl;
	cout << "                                                    ############        " << endl;
	cout << "                                                   / |  _  _  | \\      " << endl;
	cout << "                                                RIP/ |  X  X  | \\ RIP  " << endl;
	cout << "                                                  /  |    >   |  \\     " << endl;
	cout << "                                                  /   \\  X   /   \\    " << endl;
	cout << "                                                 /_____\\____/_____\\   " << endl;
	cout << "                                                        |  |            " << endl;
}


#endif