#include <iostream>
using namespace std;

#ifndef WARRIOR
#define WARRIOR
class war
{
    public:
    war(){}
    ~war(){}
    void Normal();
    void Attack();
    void Damaged();
    void Dead();
};


void war::Normal()
{
	cout <<"						   _          _      		" << endl;
	cout <<"						   \\\\   ^^   //    		" << endl;
	cout <<"						    \\\\      //     		" << endl;
	cout <<"						     &&&&&&&&&&       		" << endl;
	cout <<"						 ^^ &&&&&&&&&&&&      		" << endl;
	cout <<"						     |  _  _  |       		" << endl;
	cout <<"						     |  0  0  |^^     		" << endl;
	cout <<"						     |    >   |       		" << endl;
	cout <<"					         ^^  /\\  --  /\\		" << endl;
	cout <<"						    // \\____/ \\\\ ^^		" << endl;
	cout <<"					         ==//== |  | ==\\\\== 	" << endl;
	cout <<"					          //            \\\\  	" << endl;
  
}

void war::Attack()
{
	cout <<"						   _          _      		" << endl;
	cout <<"						   \\\\   !!   //    		" << endl;
	cout <<"						    \\\\      //     		" << endl;
	cout <<"						     &&&&&&&&&&       		" << endl;
	cout <<"						 !! &&&&&&&&&&&&&     		" << endl;
	cout <<"						     |  \\  /  |      		" << endl;
	cout <<"						     |  0  0  |!!     		" << endl;
	cout <<"						     |    >   |       		" << endl;
	cout <<"					         !!  /\\  --  /\\   	" << endl;
	cout <<"						    // \\____/ \\\\ !!		" << endl;
	cout <<"					         ==//== |  | ==\\\\== 	" << endl;
	cout <<"					          //            \\\\  	" << endl;
}

void war::Damaged()
{
	cout <<"						   _          _      		" << endl;
	cout <<"						   \\\\   $    //    		" << endl;
	cout <<"						    \\\\      //     		" << endl;
	cout <<"						     &&&&&&&&&&       		" << endl;
	cout <<"						  $ &&&&&&&&&&&&      	" << endl;
	cout <<"						     |  /  \\  |      		" << endl;
	cout <<"						     |  *  *  | $     		" << endl;
	cout <<"						     |    >   |       		" << endl;
	cout <<"					         $   /\\  $$  /\\     	" << endl;
	cout <<"						    // \\____/ \\\\  $		" << endl;
	cout <<"					         ==//== |  | ==\\\\== 	" << endl;
	cout <<"					          //            \\\\  	" << endl;
}

void war::Dead()
{
	cout <<"						   _          _      " << endl;
	cout <<"						   \\\\  RIP   //    " << endl;
	cout <<"						    \\\\      //     " << endl;
	cout <<"						     &&&&&&&&&&       " << endl;
	cout <<"						RIP &&&&&&&&&&&&      " << endl;
	cout <<"						     |  _  _  |       " << endl;
	cout <<"						     |  X  X  |RIP    " << endl;
	cout <<"						     |    >   |       " << endl;
	cout <<"					         RIP /\\   X  /\\     " << endl;
	cout <<"						    // \\____/ \\\\RIP" << endl;
	cout <<"					         ==//== |  | ==\\\\== " << endl;
	cout <<"					          //            \\\\  " << endl;
}

#endif