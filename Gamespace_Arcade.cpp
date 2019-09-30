#include "Hangman + Hints.h"
#include "survive_Header.h"
#include "snake_Header.h"
#include "UserLogin.h"
#include "Tic-Tac-Toe.h"



int main()
{
	int game, select=1;
	cout << "\n\t\t\t\t\t ******** WELCOME TO GAMESPACE ******** \n\n\n";
	//cout << "\n\t\t\t\t\t ******** WELCOME TO GAMESPACE ******** \n\n\n";
	cout << "\n\t\t\t\t\t Please login first before proceeding!  \n\n\n";
	userlogin();  //allow user to login and register their account
	while (select != 0) {
		cout <<"[ "<<usr.name<<" ]"<< " Please enter a number to choose a game to play ! \n\n";
		cout << "----------------------------------------------------------------------------------------------------\n";
		cout << "[1] for Hangman \n\n[2] for Snake and Ladder  \n\n[3] for Survive \n\n[4] for TicTacToe \n\n[0] if u want to exit \n";
		cout << "----------------------------------------------------------------------------------------------------\n";
		cout << "Enter a number : ";
		cin >> select;
		system("cls");
		if (select == 1)
			hangman();
		else if (select == 2)
			snek();
		else if (select == 3)
			survive();
		else if (select == 4)
			TicTacToe();
		else if (select == 0)
			break;
		else
			cout << "Please enter the right number :) ! \n\n";
	}
	cout<<"----------------------------------------------------------------------------------------------------";
	cout << "\n Thank you for playing our game , We hope you enjoyed our games! Feel free to play again later C: ! \n";
	cout << "----------------------------------------------------------------------------------------------------\n";
	return 0;
}