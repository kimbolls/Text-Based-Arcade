#pragma once


void rule();
void player_position();
int rolling(string);
int movement(int, string, int);
int condition(int, string, int, string);
int position1, position2, win = 0;
string  player2_name;
string player1_name;



void snek()
{

	srand(time(NULL)); //randoms seed for every start
	 
	int gerak;
	int roll; // roll = dice 

	rule();  // display rule of game
	player1_name = usr.name;  // player 1 = logged in user
	cout << "This game requires another player to play !\n";
	cout << "Please enter Player 2 name : ";
	cin >> player2_name;		// input player 2 name


	while (win == 0)
	{
		cout << "\t\t\t\t   ******** SNAKE AND LADDER GAME ******** \n";
		player_position();														 //update each players' position
		gerak = rolling(player1_name);											 //player 1 rolls dice	
		position1 = movement(position1, player1_name, gerak);					 //player 1 advance based on dice rolled
		wait(1);																 //delay 1 second for user experience smoothness
		position1 = condition(position1, player1_name, position2, player2_name); // checks player 1 position for any conditions

		if (win == 1)			// if player 1 wins , break the loop.
			break;

		gerak = rolling(player2_name);											 //player 2 rolls dice	
		position2 = movement(position2, player2_name, gerak);					 //player 2 advance based on dice rolled
		wait(1);																 //delay 1 second for user experience smoothness
		position2 = condition(position2, player2_name, position1, player1_name); // checks player 2 position for any conditions

		if (win == 1)           // break loop if any player wins
			break;	
		wait(2);				// wait 2 seconds before clearing screen
		system("cls");          // clear screen for interface cleanliness
		


	}
}
void rule(void) {
	cout << "\t\t\t\t\t****** WELCOME TO SNAKE GAME ******\n\n\n";
	cout << "\t\t\t\t    ****** RULE OF SNAKE AND LADDER GAME ******\n\n\n\n";
	cout << "\t\t            [1] Every player take turns to roll a dice.\n";
	cout << "\t\t            [2] If player found a ladder, they will advance according the ladder.\n";
	cout << "\t\t            [3] If player found a snake, they will go back according the snake!.\n";
	cout << "\t\t            [4] Whoever reaches 100 first, they will win! Simple enough right?.\n\n\n";
}
void player_position()
{

	cout << "\n\t\t\t" << player1_name << " is at [" << position1 << "]\t\t\t";  //display player 1 position
	cout << player2_name << " is at [" << position2 << "]\t\t\t" << endl;		 // display player 2 position
} 

int rolling(string p)
{
	int repeat = 0;
	int totalroll = 0;
	while (repeat != 1) {
		int roll;
		cout << "\n" << p << " please enter any number to roll dice: ";
		cin >> roll;															//user input any number to roll dice
		roll = (rand() % 6 + 1);												// randomly generated number between 1 to 6 
		if (roll == 0)
			roll += 1;															//if rolled number is 0, make it 1 instead
		cout << p << " rolled :" << roll << " !\n";								//display how many did player rolled 
		totalroll += roll;														//rolled number will be added
		if (roll == 6)															//if player rolled 6, they get to roll again
		{
			cout << "You get to roll again!\n";
			repeat = 0;
		}
		else
			repeat = 1;
	}
	return totalroll;															//total of rolled number will be returned
}

int movement(int position, string player, int roll)
{
	position += roll;															//player position will be added with total of rolled number
	if (position > 100)															//if player exceeded 100 spaces, they will go back with how much they exceeded		
	{
		int over = 0;
		over = position - 100;
		position = 100 - over;
		cout << player << " exceeded 100! Go back " << over << " spaces.";
	}
	cout << player << " is now at [" << position << "].\n";
	return position;
}

int condition(int position, string player, int positionconf, string playerconf)
{
	if (position == positionconf)  //if both players land at the same space, both need to roll. If the player who lands at the other's space rolled higher , they will advance else they will go back.
	{
		cout << player << " is at the same space as " << playerconf << "!\n";
		cout << "\n\nYou both need to roll and if " << player << " rolled higher, " << player << " will advance the same number as they rolled, or else if " << playerconf << " rolled higher," << player << " will go back the same spaces they rolled!\n\n";
		int mainplayer = rolling(player);
		int confplayer = rolling(playerconf);
		if (mainplayer > confplayer) {
			cout << player << " rolled higher! Advance " << mainplayer << " spaces!" << endl;  
			position += mainplayer;
		}
		if (confplayer > mainplayer) {
			cout << playerconf << " rolled higher! Too bad..." << player << " will go back " << mainplayer << " spaces" << endl;
			position -= mainplayer;
		}
		wait(2);
	}
	if (position <= 0) //if player managed to go back in spaces until below 0 , make it 0
		position = 0;
	if (position == 1)    // player found a ladder, advance in space
	{
		cout << player << " found a ladder , Move from " << position << " to 38 !\n";   
		cout << player << " is now at [38] .\n";
		position = 38;
	}
	if (position == 4)
	{
		cout << player << " found a ladder , Move from " << position << " to 14 !\n";
		cout << player << " is now at [14] .\n";
		position = 14;
	}
	if (position == 8)
	{
		cout << player << " found a ladder , Move from " << position << " to 30 !\n";
		cout << player << " is now at [30] .\n";
		position = 30;
	}
	if (position == 21)
	{
		cout << player << " found a ladder , Move from " << position << " to 42 !\n";
		cout << player << " is now at [42] .\n";
		position = 42;
	}
	if (position == 28)
	{
		cout << player << " found a ladder , Move from " << position << " to 74 !\n";
		cout << player << " is now at [74] .\n";
		position = 74;
	}
	if (position == 32)  //player found a snake , go back in spaces
	{
		cout << player << " found a snake! How unlucky. Move from " << position << " to 10 !\n";
		cout << player << " is now at [10] .\n";
		position = 10;
	}
	if (position == 36)
	{
		cout << player << " found a snake! How unlucky. Move from " << position << " to 6 !\n";
		cout << player << " is now at [6] .\n";
		position = 6;
	}
	if (position == 48)
	{
		cout << player << " found a snake! How unlucky. Move from " << position << " to 26 !\n";
		cout << player << " is now at [26] .\n";
		position = 26;
	}
	if (position == 50)
	{
		cout << player << " found a ladder , Move from " << position << " to 67 !\n";
		cout << player << " is now at [67] .\n";
		position = 67;
	}
	if (position == 62)
	{
		cout << player << " found a snake! How unlucky. Move from " << position << " to 18 !\n";
		cout << player << " is now at [18] .\n";
		position = 18;
	}
	if (position == 80)
	{
		cout << player << " found a ladder , Move from " << position << " to 99 !\n";
		cout << player << " is now at [99] .\n";
		position = 99;
	}
	if (position == 71)
	{
		cout << player << " found a ladder , Move from " << position << " to 92 !\n";
		cout << player << " is now at [92] .\n";
		position = 92;
	}
	if (position == 88)
	{
		cout << player << " found a snake! How unlucky. Move from " << position << " to 24 !\n";
		cout << player << " is now at [24] .\n";
		position = 24;
	}
	if (position == 95)
	{
		cout << player << " found a snake! How unlucky. Move from " << position << " to 56 !\n";
		cout << player << " is now at [56] .\n";
		position = 56;
	}
	if (position == 97)
	{
		cout << player << " found a snake! How unlucky. Move from " << position << " to 78 !\n";
		cout << player << " is now at [78] .\n";
		position = 78;
	}
	
	if (position == positionconf)  // both player at the same space
	{
		cout << player << " is at the same space as " << playerconf << "!\n";
		cout << "\n\nYou both need to roll and if " << player << " rolled higher, " << player << " will advance the same number as they rolled, or else if " << playerconf << " rolled higher," << player << " will go back the same spaces they rolled!\n\n";
		int mainplayer = rolling(player);
		int confplayer = rolling(playerconf);
		if (mainplayer > confplayer) {
			cout << player << " rolled higher! Advance " << mainplayer << " spaces!" << endl;
			position += mainplayer;
		}
		if (confplayer > mainplayer) {
			cout << playerconf << " rolled higher! Too bad..." << player << " will go back " << mainplayer << " spaces" << endl;
			position -= mainplayer;
		}
		wait(2);
	}
	if (position == 100) {   //if a player reaches 100 exactly, no more no less, they will win.
		win = 1;
		cout << player << " Have reached the end succesfully and won the game! Congratulations!!";
	}

	return position;  //return player position


}