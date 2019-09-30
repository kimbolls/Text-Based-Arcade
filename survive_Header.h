void intro(void);			//intro script
void scene1(void);			//still script
void scene2(void);			//Day scene
void scene3(void);			//Night scene
void sceneEnd(void);		//Ending scene (die or survive)
int inputCheck(int);		//only allow user to input 1-3
void inputCamp(void);		//user choose to setup camp
void inputExp(void);		//user choose to gather needs
void getWood(void);			//items for collect woods
void expCamp(void);			//items for explore camp area
void expArea(void);			//items for gather needs
void builtShelter(void);	//built shelter
void sleep(void);			//sleep scene
int inputDay(void);			//ask user to (setup camp/ gather needs)
void p2Item(int);			//Stranger's item gather
void inventory(void);		//show health status & inventory
void playerStatus(int);		//(add/ minus) health
void wait(int);				//add gap between scripts
int survive(void);			//function to start game

string p2;
int health = 100, energy = 100, status = 1, day = 0, time1;		//game stats
int wood = 0, leaf = 0, shelter = 0;							//
int emptyBottle = 0, cleanWater = 0, rope = 0;					//Inventories
int healingPlant = 0, plasticSheet = 0, emergencyPhone = 0;		//

int survive()
{
	p2 = "Stranger";
	status = 1;					//reset back status(death) (for second play)
	srand(time(NULL));			//give random seed to rand()
	intro();
	scene1();
	while (status == 1)
	{
		scene2();
		scene3();
	}
	sceneEnd();

	return 0;
}

void intro(void)			//just scripts
{
	cout << p2 << ": Hey, wake up...\n";
	wait(1);
	cout << p2 << ": Wake up!\n";
	wait(2);
	cout << usr.name << ": Ugh... What happened?\n";
	wait(2);
	cout << p2 << ": Our bus just crashed. Seems like we are the only survivor.\n";
	wait(2);
	cout << usr.name << ": Ah! my head hurts.\n";
	wait(2);
	cout << p2 << ": We need to get out of this forest.\n";
	wait(2);
	cout << usr.name << ": You are right...\n";
	wait(1);
	cout << usr.name << ": Wait, I'm sorry but what's your name?\n\n";
	wait(1);
	cout << "Enter the Strangers name: ";
	cin.ignore(256, '\n');						//clear buffer
	getline(cin, p2);							//changestranger name
	cout << p2 << ": And your's is? ";
	wait(1);
	cout << "\n\nMy name is " << usr.name << endl;
	cout << p2 << ": Ok good, now we know each other's name, we need to move out because the bus's tank had a leak.\n\n";
	wait(3);
}

void scene1(void)
{
	int a;
	cout << "choose your action: ";
	cout << "(1- move / 2- Sit down)";
	a = inputCheck(2);
	if (a == 2) {							//speedrun mode (death)
		wait(1);
		cout << usr.name << ": Sorry, I don't have the energy.\n";
		wait(2);
		cout << "Pssst... BOOM! Your Are DEAD.\nThe bus had a leaked tank and a spark tringgered the explosion.  I lived a good but short life, the life I choose. the ending may not be as great, but i did what i love.... Sitting Down beside a leaked tank. \n";
		wait(3);
		status = 0;
	}
	else
	{
		wait(1);
		cout << "Moving...\n";
		wait(1);
		cout << "Moving...\n";
		wait(1);
		cout << p2 << ": I think this is far enough, beside this lake seems like a good spot to stay.\n";
	}
}

void scene2(void)
{
	if (status == 1)
	{
		int a;
		a = inputDay();			//ask user to (stay / explore)
		if (a == 1)
		{
			inputCamp();		//actions at camp
			p2Item(1);			//random items attained by stranger
		}
		else
		{
			inputExp();			//actions (gather needs)
			p2Item(2);			//random items attained by stranger
		}
		inventory();			//shows health status/ inventory
	}
}

void scene3(void)
{
	if (status == 1)			//check if user is not dead yet
	{
		wait(1);
		cout << "\n\nIts getting late, we need to get some sleep\n";
		sleep();				//actions before sleep
	}
}

void sceneEnd(void)
{
	if (emergencyPhone > 0)			//if emergencyPhone is found, you win
	{
		wait(1);
		cout << "\n\nHey, we could use this phone to call for help!\n";
		wait(2);
		cout << "*Dialing*\n";
		wait(1);
		cout << p2 << ": Hello? can you hear me?\n";
		wait(1);
		cout << p2 << ": Yes....\n";
		wait(1);
		cout << p2 << ": Yup\n";
		wait(1);
		cout << p2 << ": There is two of us\n";
		wait(1);
		cout << p2 << ": we are at... **** ****\n";
		wait(1);
		cout << p2 << ": Great, help is on the way!\n\n";
		wait(1);
		cout << "*****CONGRATULATION!*****\n\n";
		wait(1);
		cout << "You have survived for " << day << " days.\n\n";
	}
	else						//you are dead
	{
		wait(1);
		cout << "\n\nYou Are Dead , " << usr.name;
		wait(1);
		cout << "\nSeems like survival skill is what you lack.\n\n";
	}
}

int inputCheck(int a)
{
	int c;				//the return value(int)
	string b = "0";		//input (string)
	cin >> b;
	switch (a)			//set limit user can input (1/1&2/1&2&3)
	{
	case 1:
		while (b != "1")
		{
			cout << "*Only insert available option*";
			cin >> b;
		}
	case 2:
		while (b != "1" && b != "2")
		{
			cout << "*Only insert available option*";
			cin >> b;
		}
	case 3:
		while (b != "1" && b != "2" && b != "3")
		{
			cout << "*Only insert available option*";
			cin >> b;
		}
	}
	c = stoi(b);			//change string to int
	return c;
}

void inputCamp(void)		//setup camp
{
	int b = 0;
	switch (day)			//change script according to day
	{
	case 1:
		wait(1);
		cout << p2 << ": Great, now I'll find as much resources as I can, and you can set the camp.\n\n";
		break;
	case 2:
		wait(1);
		cout << p2 << ": Okay, today I'll find some resources and you can improvise our camp";
	}
	for (time1 = 6; time1 > 0; time1--)		//limit to 6 times
	{
		wait(1);
		cout << "\nClock : " << time1 << " Hours before dark.\n";		//clock before dark
		cout << "(1- Collect wood / 2- Explore Area / 3- Built Shelter)";
		b = inputCheck(3);
		switch (b)
		{
		case 1:
			getWood();
			break;
		case 2:
			expCamp();
			break;
		case 3:
			builtShelter();
			break;
		}
	}
}

void inputExp(void)			//gather needs
{
	int b = 0;
	switch (day) {
	case 1:
		wait(1);
		cout << p2 << ": Great, now I'll setup the camp with tent, and you can find resources.\n\n";
		cout << "1- explore Left side (1day) / 2- explore Right side (1day)";
		b = inputCheck(2);
		expArea();
		break;
	default:
		wait(1);
		cout << p2 << ": Ok, now I'll improvise our camp, and you can find resources.\n\n";
		cout << "1- explore Left side (1day) / 2- explore Right side (1day)";
		b = inputCheck(2);
		expArea();
	}
}

void getWood(void)			//collect wood
{
	wood = wood + 2;
	leaf = leaf + 3;
	wait(1);
	cout << "Item attained: wood x2 , leaf x3\n";
}

void expCamp()				//explore camp area
{
	int a;
	a = rand() % 100 + 1;		//random number (1-100)
	wait(1);
	if (a < 41)				//different percentage of item found
	{
		wood++;
		cout << "Item Attained: Wood x1\n";
	}
	else if (a < 71)
	{
		rope++;
		cout << "Item Attained: Rope x1\n";
	}
	else if (a < 81)
	{
		emptyBottle++;
		cout << "Item Attained: Empty bottle x1\n";
	}
	else if (a < 96)
	{
		healingPlant++;
		cout << "Item Attained: Healing plant x1\n";
	}
	else if (a < 100)
	{
		plasticSheet++;
		cout << "Item Attained: Plastic Sheets x1\n";
	}
	else if (a == 100)				//chances is (1/100)
	{
		emergencyPhone++;
		cout << "Item Attained: Emergency Phone\n";
		status = 0;
	}
}

void expArea(void)			//script (wondering in the woods)
{
	cout << "\n";
	switch (day)			//script depending on day
	{
	case 1:
		wait(1);
		cout << usr.name << ": Should i stop now?\n";
		wait(2);
		cout << usr.name << ": I guess this is far enough\n";
		break;
	case 2:
		wait(1);
		cout << usr.name << ": Should i stop now?\n";
		wait(2);
		cout << usr.name << ": Hmm..., can " << p2 << " be trusted?\n";
		wait(2);
		cout << usr.name << ": Hey, I found Goods!\n";
		break;
	case 3:
		wait(1);
		cout << usr.name << ": Should i stop now?\n";
		wait(2);
		cout << usr.name << ": Have i been here before?\n";
		wait(2);
		cout << usr.name << ": Hey, what is that?\n";
		break;
	default:
		wait(1);
		cout << usr.name << ": Should i stop now?\n";
		wait(1);
		cout << usr.name << ": Wait the minute.... where am I?\n";
		wait(1);
		cout << usr.name << ": can I take that back?\n";
	}

	for (time1 = 6; time1 > 0; time1--)			//count down clock
	{
		wait(1);
		cout << "\nClock : " << time1 << " Hours before dark.";
	}
	wait(1);
	cout << "\n\n";

	for (time1 = 2; time1 > 0; time1--)			//items found
	{
		int a;
		a = rand() % 100 + 1;
		if (a < 11)
		{
			wood++;
			cout << "Item Attained: Wood x1\n";
		}
		else if (a < 31)
		{
			rope++;
			cout << "Item Attained: Rope x1\n";
		}
		else if (a < 51)
		{
			emptyBottle++;
			cout << "Item Attained: Empty bottle x1\n";
		}
		else if (a < 76)
		{
			healingPlant++;
			cout << "Item Attained: Healing plant x1\n";
		}
		else if (a < 90)
		{
			plasticSheet++;
			cout << "Item Attained: Plastic Sheets x1\n";
		}
		else if (a < 91 + day)				//chances increases everyday (limit: 10/100)
		{
			emergencyPhone++;;
			cout << "Item Attained: Emergency Phone\n";
			status = 0;
		}
		else
		{
			wood++;
			cout << "Item Attained: Wood x1\n";
		}
	}
}

void builtShelter(void)			//check sufficiency of item
{
	wait(1);
	if (wood > 3 && rope > 1 && leaf > 4)
	{
		if (shelter == 0)
			cout << "Atleast we have a shelter now.\n";
		else
			cout << "Now we have a better shelter.\n";
		wood = wood - 4;
		rope = rope - 2;
		leaf = leaf - 5;
		shelter++;
	}
	else
	{
		cout << "We don't have enough resources\n";
		time1++;					//increase loop condition
	}
}

void sleep(void)							//before sleep
{
	int a = 0, b, c, fire = 0;
	while (a != 1)
	{
		cout << p2 << ": What do you want to do tonight?\n\n";
		cout << "(1- sleep / 2- Start fire / 3- Patch wound)";
		a = inputCheck(3);
		switch (a)
		{
		case 2:				//start fire
			if (wood > 0 && fire == 0)
			{
				wait(1);
				cout << "\nItem used: wood 1x\n";
				wood = wood - 1;
				wait(1);
				cout << "\n[Fire crackle]\n";
				wait(1);
				cout << "This fire should keep us from danger\n";
				fire = 1;
				if (emptyBottle > 0)
				{
					wait(1);
					cout << p2 << ": anything next?\n\n";
					cout << "(1- boil water)";
					b = inputCheck(1);
					if (b == 1 && emptyBottle > 0)
					{
						c = emptyBottle;
						emptyBottle = 0;
						cleanWater = c;
						wait(1);
						cout << "Item Attained: Clean Water " << c << "x.\n";
						cout << "(1- sleep)";
						a = inputCheck(1);
					}
				}
			}
			else if (fire == 1)
			{
				wait(1);
				cout << p2 << ": We already have a Fireplace right here.\n";
			}
			else
			{
				wait(1);
				cout << p2 << ": We don't have any woods.\n";
				wait(1);
				cout << p2 << ": It's very dangerous but we can do nothing.\n";
				wait(1);
				cout << p2 << ": Now, the only thing we can do is sleep.\n";
			}
			break;
		case 3:							//patch wound
			if (health == 100)				
			{
				cout << p2 << ": Your health is full right now.\n";
			}
			else if (healingPlant > 0)
			{
				wait(1);
				cout << "\nItem used: healing plant 1x\n";
				healingPlant--;
				wait(1);
				cout << "\nHealth increase 10%\n";
				health += 10;
			}
			else
				cout << "\nWe don't have any of that.\n";
			break;
		}
	}

	playerStatus(fire);				//(add/minus) player health

	if (health < 1)
		status = 0;
	else
	{
		wait(1);
		cout << "\nYou slept like a baby...\n";
		wait(1);
		cout << "Now Wake up!\n\n";
	}
}

int inputDay(void)						//morning scene
{
	int b = 0;
	day += 1;
	switch (day) {						//script depends on day
	case 1:
		cout << "Ok, let's split the work on gathering resources and setting up the camp.\n";
		wait(1);
		cout << "What do you want to do?\n\n";
		wait(1);
		cout << "(1- Setup camp / 2- Gather needs)";
		b = inputCheck(2);
		break;
	default:
		cout << p2 << ": We have survive another day.\n";
		wait(1);
		cout << p2 << ": So, what do you want to do today?\n\n";
		wait(1);
		cout << "(1- Setup camp / 2- Gather needs)";
		b = inputCheck(2);
	}
	return b;
}

void p2Item(int a)					//item found by stranger
{
	wait(1);
	cout << "\n";
	cout << p2 << ": look at what I've got.\n\n";
	switch (a)						//if the stranger (setup camp/ gather needs)
	{
	case 1:
		for (time1 = 2; time1 > 0; time1--)
		{
			wait(1);
			int a;
			a = rand() % 100 + 1;
			if (a < 11)
			{
				wood++;
				cout << "Item Attained: Wood x1\n";
			}
			else if (a < 31)
			{
				rope++;
				cout << "Item Attained: Rope x1\n";
			}
			else if (a < 51)
			{
				emptyBottle++;
				cout << "Item Attained: Empty bottle x1\n";
			}
			else if (a < 76)
			{
				healingPlant++;
				cout << "Item Attained: Healing plant x1\n";
			}
			else if (a < 90)
			{
				plasticSheet++;
				cout << "Item Attained: Plastic Sheets x1\n";
			}
			else if (a < 91 + day)
			{
				emergencyPhone++;;
				cout << "Item Attained: Emergency Phone\n";
				status = 0;
			}
			else
			{
				wood++;
				cout << "Item Attained: Wood x1\n";
			}
		}
		break;
	case 2:
		wait(1);
		getWood();
		expCamp();
		if (wood > 3 && rope > 1 && leaf > 4)
		{
			if (day == 1)
				cout << "Atleast we have a shelter now.\n";
			else
				cout << "Now this is a better shelter.\n";
			wood = wood - 4;
			rope = rope - 2;
			leaf = leaf - 5;
			shelter++;
		}
	}
}

void inventory(void)					//show player health & inventory
{
	wait(1);
	cout << "\n\n****** LIFE STATUS ******";
	cout << "\n\nHealth    [";
	for (int a = 0; a < health - 10; a += 10)
		cout << "|";
	cout << "]" << health << "%";
	cout << "\nEnergy    [";
	for (int a = 0; a < energy - 10; a += 10)
		cout << "|";
	cout << "]" << energy << "%\n";
	wait(1);
	cout << "\n******* Inventory *******\n";
	if (wood > 0)
		cout << "\nwood: " << wood;
	if (leaf > 0)
		cout << "\nleaf: " << leaf;
	if (rope > 0)
		cout << "\nrope: " << rope;
	if (emptyBottle > 0)
		cout << "\nemptyBottle: " << emptyBottle;
	if (cleanWater > 0)
		cout << "\nclean water: " << cleanWater;
	if (healingPlant > 0)
		cout << "\nhealing plant: " << healingPlant;
	if (plasticSheet > 0)
		cout << "\nplastic sheet: " << plasticSheet;
	if (emergencyPhone > 0)
		cout << "\nemergency phone: " << emergencyPhone;
	cout << "\n\n*************************";
	wait(1);
}

void playerStatus(int fire)							//(add/minus) player health
{
	int b = 0;
	if (shelter == 0 && fire == 0)					//no shelter + no fire (-30 health)
		health -= 30;
	else if (shelter == 0 || fire == 0)				//no shelther / fire (-10 health)
		health -= 10;

	if (cleanWater > 0)								//check availability of clean water
	{
		wait(1);
		cout << p2 << ": we need to drink to survive\n\n";
		wait(1);
		cout << "Item Used: clean water x1\n\n";
		cleanWater--;
		energy += 30;
		if (energy > 100)							//if energy exceed 100
		{
			b = energy - 100;
			energy -= b;
		}
	}
	else									//no water
	{
		wait(1);
		cout << p2 << ": We don't have any water to drink.\n";
		wait(1);
		cout << p2 << ": We need to make clean water fast\n";
		energy -= 30;
		if (energy < 0)
		{
			b = energy;
			energy -= b;
		}
	}
	wait(1);
	cout << "Now, let's sleep\n";

	if (energy < 1)										//minus health when energy: 0
		health -= 20;

}

void wait(int wait_time)								//time gap between scripts
{
	long *start_time = new long;						//declare variable (datatype : long)
	*start_time = time(0);								//assign time to variable (*start_time)

	while ((*start_time + wait_time) > time(0)) {		//check if set time has pass
	};

	delete start_time;									//freeing memory
}