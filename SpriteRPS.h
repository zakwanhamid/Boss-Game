#include <iostream>
using namespace std;

class RPSsprite
{

public:
    RPSsprite(){}
    ~RPSsprite(){}

	void rockLeft();
	void rockRight();
	void paperLeft();
	void paperRight();
	void scissorLeft();
	void scissorRight();

	void RR();
	void RP();
	void RS();
	void PR();
	void PP();
	void PS();
	void SR();
	void SP();
	void SS();

	void checkRPS(int, int);
};


void RPSsprite::rockLeft()
{
	cout<< "                                  !BOSS!   " << endl;
	cout<< "                                  _______    " << endl;
	cout<< "                                 | | | | |   " << endl;
	cout<< "                                 |_|_|_|_|   " << endl;
	cout<< "                                 |___|   |   " << endl;
	cout<< "                                  |______|   " << endl;
	cout<< "                                 		     " << endl << endl;;

}

void RPSsprite::rockRight()
{
	cout<< "                                                                   _______    " << endl;
	cout<< "                                                                  | | | | |   " << endl;
	cout<< "                                                                  |_|_|_|_|   " << endl;
	cout<< "                                                                  |___|   |    " << endl;
	cout<< "                                                                   |______|     " << endl << endl;
	cout<< "                                                                   !PLAYER!   " << endl;
	cout<< "                                 		     " << endl << endl;;

}

void RPSsprite::paperLeft()
{
	cout<< "                                  !BOSS!   		" << endl;
	cout<< "                                  _ _ _ _   	" << endl;
	cout<< "                                 | | | | |   	" << endl;
	cout<< "                              _  | | | | |   	" << endl;
	cout<< "                              \\ \\| | | | |   	" << endl;
	cout<< "                               \\         |   	" << endl;
	cout<< "                                |        /    	" << endl;
	cout<< "                                 \\______/    	" << endl;
}
void RPSsprite::paperRight()
{
	cout<< "                                                                   _ _ _ _   	" << endl;
	cout<< "                                                                  | | | | |   	" << endl;
	cout<< "                                                               _  | | | | |   	" << endl;
	cout<< "                                                               \\ \\| | | | |   	" << endl;
	cout<< "                                                                \\         |   	" << endl;
	cout<< "                                                                 |        /    	" << endl;
	cout<< "                                                                  \\______/    	" << endl << endl;
	cout<< "                                                                  !PLAYER!   		" << endl;

}

void RPSsprite::scissorLeft()
{
	cout<<"                                   !BOSS!   		" << endl;
	cout<<"                                  __    __    	" << endl;
	cout<<"                                  \\ \\  / /     " << endl;
	cout<<"                                   \\ \\/ /      " << endl;
	cout<<"                                   _\\_ /___    	" << endl;
	cout<<"                                  |___|| | |   	" << endl;
	cout<<"                                  |    |_|_|   	" << endl;
	cout<<"                                   \\______/    	" << endl;
} 

void RPSsprite::scissorRight()
{
	cout<<"                                                                  __    __    " << endl;
	cout<<"                                                                  \\ \\  / /      " << endl;
	cout<<"                                                                   \\ \\/ /      " << endl;
	cout<<"                                                                   _\\_ /___    " << endl;
	cout<<"                                                                  |___|| | |   " << endl;
	cout<<"                                                                  |    |_|_|   " << endl;
	cout<<"                                                                   \\______/   " << endl << endl;
	cout<< "                                                                   !PLAYER!   " << endl;


}


void RPSsprite::RR()
{
    rockLeft();
    cout << "                                                 -----VS-----" << endl;
    rockRight();
}
void RPSsprite::RP()
{
    rockLeft();
    cout << "                                                 -----VS-----" << endl;
    paperRight();
}
void RPSsprite::RS()
{
    rockLeft();
    cout << "                                                 -----VS-----" << endl;
    scissorRight();
}
void RPSsprite::PR()
{
    paperLeft();
    cout << "                                                 -----VS-----" << endl;
    rockRight();
}
void RPSsprite::PP()
{
    paperLeft();
    cout << "                                                 -----VS-----" << endl;
    paperRight();
}
void RPSsprite::PS()
{
    paperLeft();
    cout << "                                                 -----VS-----" << endl;
    scissorRight();
}
void RPSsprite::SR()
{
    scissorLeft();
    cout << "                                                 -----VS-----" << endl;
    rockRight();
}
void RPSsprite::SP()
{
    scissorLeft();
    cout << "                                                 -----VS-----" << endl;
    paperRight();
}
void RPSsprite::SS()
{
    scissorLeft();
    cout << "                                                 -----VS-----" << endl;
    scissorRight();
}

void RPSsprite::checkRPS(int compInput, int userInput)
{
	switch (compInput)
	{
		case 1:
		switch (userInput)
		{
			case 1:
			RR();	
			break;

			case 2:
			RP();
			break;

			case 3:
			RS();
			break;

			default:
			break;
		}
		break;

		case 2:
		switch (userInput)
		{
			case 1:
			PR();	
			break;

			case 2:
			PP();
			break;

			case 3:
			PS();
			break;

			default:
			break;
		}
		break;

		case 3:
		switch (userInput)
		{
			case 1:
			SR();	
			break;

			case 2:
			SP();
			break;

			case 3:
			SS();
			break;

			default:
			break;
		}
		break;

		default:
		break;
	}
}


 
