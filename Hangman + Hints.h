#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<fstream>
using namespace std;
int checkguess(char, string, string&);	//compare user input & actual answer
void interface(int, int);	//the look of the system will be consistent
string broadcast = "- Let's Play! -";	//system's responds to user input
struct user {
	string name;
	string pass;
}usr;


int hangman()
{
	srand(time(NULL));	//random every seed
	char guess;
	int match;
	string wordguess;
	string clues;
	string unknown;
	string wordlist[10] = { "malaysia","indonesia","china","japan","india","korea","thailand","vietnam","singapore","philippines" };	//words to be guess by the user
	string cluelist[10] = { "A multi-religious country",
							"A country that is the main cause of haze that mainly affects East Malaysia",
							"A country that considered as the largest Economy in Asia",
							"The country's currency is called Yen",
							"The second most populated country in Asia",
							"A country considered as the Plastic Surgery Capital of the World",
							"The only Southeast Asian country that was never colonized by an European country",
							"A country that is called The Land of Blue Dragon",
							"The second smallest country of Asia",
							"A country that is also known as Pearl of the Orient Seas" 
						  };
	int i = rand() % 10;	//randomize which word to pick
	wordguess = wordlist[i];	//put into a variable
	clues = cluelist[i];
	unknown.assign(wordguess.length(), '*');	// set word = * for indicater
	int num_of_wrong_guess = 0;
	int max_tries = 5; //maximum attempts

	while (num_of_wrong_guess < max_tries)
	{
		interface(max_tries, num_of_wrong_guess);
		cout << "\n\n\t[ " << unknown << " ]";
		cout << "\n\n\tHint: " << clues << endl;
		cout << "\n\n\tGuess a letter one by one: ";
		cin >> guess;	// get user input on what to guess
		match = checkguess(guess, wordguess, unknown);
		if (match == 0)
		{
			broadcast = "- OOPS .. You guessed it wrong! -";	// no matches = wrong guess
			num_of_wrong_guess++;
		}
		else
		{
				broadcast = "- NICE! You guess a letter! -";	//matches = correct guess
		}



		if (wordguess == unknown)
		{
			broadcast = "- Congratulations! You got it right! You're so clever! -";
			interface(max_tries, num_of_wrong_guess);
			cout << "\n\tWell Done!" << endl;	//display answer when user guessed it right
			break;
		}
	}
	if (num_of_wrong_guess == max_tries)
	{
		broadcast = "- Oh Nooo! You've been hanged. -";
		interface(max_tries, num_of_wrong_guess);
		cout << "\n\tGAME OVER! The correct answer was : " << wordguess << endl;	//display answer when user failed to guessed it right
	}
	cin.ignore();	//ignores the next input from the stream
	cin.get();	//reads an input character and store it in ch
	return 0;
}


int checkguess(char userguess, string secretword, string &unknownword)
{
	int correct = 0;
	int j = secretword.length();
	for (int i = 0; i < j; i++)
	{

		if (userguess == unknownword[i])	//if same with previously guessed word
			return 0;

		if (userguess == secretword[i])
		{
			unknownword[i] = userguess;
			correct++;
		}
	}
	return correct;
}

void interface(int max_tries, int num_of_wrong_guess)	//the look of the system will be consistent
{
	system("cls");

	cout << "\n\t~ HANGMAN GAME ~" << endl;
	cout << "\n\tGeneral Knowledge of Asia Countries.";
	cout << "\n\tTry to guest the country." << endl;
	cout << "\n\tYou have " << max_tries - num_of_wrong_guess << " guessses left !";	//tells user how many more attempts they can do
	cout << "\n\n\t" + broadcast << endl;
	cout << "\n\t-------------------------------------------------------------------------------------------------------" << endl;
}