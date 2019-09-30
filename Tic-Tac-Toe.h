char square[9] = {'0','1','2','3','4','5','6','7','8'};
void menu(void);								//interface of rules
void playername(void);							//take name input from user
int checkwin(void);								//check the grid for win( 3 box straight consider win)
int mark(string, int);							//mark the player position
void display(void);								// display grid interface
string player2;
void TicTacToe(void);

void TicTacToe(void)
{
	int box, result = 0, flag = 0, available = 0;
	float i = 0;
	menu();
	playername();
	cout << "\n\n";
	display();

	for (i = 0; i < 18;)
	{
		available = 0;							//Player 1
		while (available == 0)
		{
			cout << "\n";
			cout << "\n" << usr.name << " enter number into the Box : ";
			cin >> box;
			available = mark(usr.name, box);
			cout << "\n";
			display();
			result = checkwin();
			if (result == 1)
			{
				cout << "\nCongratulations! Player " << usr.name << " has Won ";
				flag = 1;
				i = 18;
				break;
			}
			else if (result == 2)
			{
				cout << "\nCongratulations! Player " << player2 << " has Won ";
				flag = 1;
				i = 18;
				break;
			}
		}
		i += 2;
		if (i == 18)
			break;
		if (flag == 1)
			break;

		available = 0;							//Player 2
		while (available == 0)
		{
			cout << "\n" << player2 << " enter number into the Box : ";
			cin >> box;
			available = mark(player2, box);
			cout << "\n";
			system("cls");
			display();
			result = checkwin();
			if (result == 1)
			{
				cout << "\nCongratulations! Player " << usr.name << " has Won ";
				flag = 1;
				i = 18;
				break;
			}
			else if (result == 2)
			{
				cout << "\nCongratulations! Player " << player2 << " has Won ";
				flag = 1;
				i = 18;
				break;
			}
		}
		i += 2;
		if (flag == 1)
			break;
	}
	if (flag == 0)
	{
		cout << " \nSorry, The game is a draw ";
	}
}
void menu(void)									//interface of rules
{
	cout << "\t\t\t\t\t****** WELCOME TO TIC TAC TOE GAME ******\n";
	cout << "\t\t\t\t        ****** RULE OF TIC TAC TOE GAME ******\n\n";
	cout << "\t\t            [1] There are 9 box.\n";
	cout << "\t\t            [2] There is 3 row and 3 columns.\n";
	cout << "\t\t            [3] There are 3 box in a row and column.\n";
	cout << "\t\t            [4] The box start with number 0 and finish at number 8.\n";
	cout << "\t\t            [5] Every player take turns to pick a box.\n";
	cout << "\t\t            [6] If player got 3 box in straight line, he or she wins!.\n\n\n";
}
void playername(void)							//take name input from user
{
	cout << "Please enter your name player 2 : ";
	cin >> player2;
}
int checkwin(void)								//check the grid for win( 3 box straight consider win)
{
	if (square[0] == square[1] && square[1] == square[2])
	{
		if (square[0] == 'X')
			return 1;
		else
			return 2;
	}
	if (square[3] == square[4] && square[4] == square[5])
	{
		if (square[4] == 'X')
			return 1;
		else
			return 2;
	}
	if (square[6] == square[7] && square[7] == square[8])
	{
		if (square[6] == 'X')
			return 1;
		else
			return 2;
	}
	if (square[0] == square[3] && square[3] == square[6])
	{
		if (square[1] == 'X')
			return 1;
		else
			return 2;
	}
	if (square[1] == square[4] && square[4] == square[7])
	{
		if (square[1] == 'X')
			return 1;
		else
			return 2;
	}
	if (square[2] == square[5] && square[5] == square[8])
	{
		if (square[2] == 'X')
			return 1;
		else
			return 2;
	}
	if (square[0] == square[4] && square[4] == square[8])
	{
		if (square[0] == 'X')
			return 1;
		else
			return 2;
	}
	if (square[2] == square[4] && square[4] == square[6])
	{
		if (square[2] == 'X')
			return 1;
		else
			return 2;
	}
	if (square[0] == square[3] && square[3] == square[6])
	{
		if (square[0] == 'X')
			return 1;
		else
			return 2;
	}
	else
		return 0;
}
int mark(string player, int box)					//mark the player position
{
	int available=0;
	if (player == usr.name && square[box] != 'X' && square[box] != 'O')
	{
		square[box] = 'X';
		available = 1;
	}
	else if (player == player2 && square[box] != 'X' && square[box] != 'O')
	{
		square[box] = 'O';
		available = 1;
	}
	else
		cout << "try again";
	return available;
}
void display(void)									//display grid interface
{
	int i = 0;
	for (i = 0; i < 9; i++)
	{
		cout << square[i] << "\t";
		if (i == 2 || i == 5 || i == 8)
			cout << "\n";
	}
}