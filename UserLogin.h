using namespace std;


int login(void);
int reg(void);
string ToAscii(string);			//change password to ascii code 
void userlogin(void);



void userlogin(void)
{
	int i = 2,j=0;
	cout <<endl<<endl<< "\t\t\t\t\t\t   User Verification\n\n\n";
	
	while (i == 2) {
		cout << "[1- Register | 2-Login] : ";
		cin >> j;
		i = 1;
		if (j == 1)
		{
			while (i == 1)
				i = reg();
			i = 2;
		}
		else
		{
			i = 1;
			while (i == 1)
				i = login();
		}

	}
}

int login(void)
{
	int count = 0, get = 1;
	string  x, y;
	ifstream username, password;

	cout << "\n\t\t\t\t\t	  ******** Login ********\n\n";
	cout << "Enter username: ";
	cin >> usr.name;
	cout << "Password: ";
	cin>>usr.pass;
	username.open("username.txt");
	while (!username.eof() && get == 1)				//check every username in file
	{
		username >> x;
		if (usr.name == x)				//if username found
			get = 0;
		else
			count++;				//count number of line to check password 
	}
	username.close();
	if (get == 0)
	{
		password.open("pass.txt");
		for (; count > -1; count--)			//get the password based on the line of username
		{
			password >> y;
		}
		password.close();
		usr.pass = ToAscii(usr.pass);				//compare ascii code of entered and ascii from file
		if (usr.pass == y)
		{	
			system("cls");
			cout << "\t\t\t\t\t ******** WELCOME TO GAMESPACE ******** \n\n\n";
			cout << "\nLogin successful , Welcome [ " << usr.name << " ] ! \n\n";
		}
		else
		{
			cout << "\nOpss wrong password\n";
			cout << "\n [1] to try again [2] to cancel : ";
			cin >> get;
			cout << endl << endl;
			
		}
	}
	else					//if either pass/username is wrong
	{
		cout << "\nSorry, wrong username or password\n";
		cout << "\n [1] to try again [2] to cancel : ";
		cin >> get;
		cout << endl << endl;
	}
	return get;
}

int reg(void)
{
	int count = 0, get = 0;
	string name, pass, x, y;
	ifstream username;

	cout << "\n\t\t\t ******** Register ******** \n\n";
	cout << "enter username: ";
	cin >> name;
	username.open("username.txt");
	while (!username.eof() && get == 0)
	{
		username >> x;
		if (name == x)			//check availability of username
			get = 1;
		else
			count++;			//to check the specific user's password
	}
	username.close();
	if (get == 0)				//if username is available
	{
		ofstream username;
		username.open("username.txt", ofstream::app);
		username << name << "\n";						//output username to username.txt file
		username.close();

		ofstream password;
		cout << "Password: ";
		cin >> pass;
		pass = ToAscii(pass);							//change password to ascii
		password.open("pass.txt", ofstream::app);
		password << pass << "\n";						//output to pass.txt file
		
		password.close();
		system("cls");
		cout << "\t\t\t\t\t ******** WELCOME TO OUR ARCADE ******** \n\n\n";
		cout << "Register successfull \n\n";
	}
	else							//if username is not available
	{
		cout << "\nUsername unavailable\n";
		cout << "\n [1] to try again [2] to cancel : ";
		cin >> get;
		cout << endl << endl;
	}
	return get;
}

string ToAscii(string pass)
{
	string converted, NormalPass;
	char key = 'A';							//key to change the calculation of ascii conversion
	int i, ToAscii[100];
	for (i = 0; i < pass.size(); i++)		//convert to ascii value
	{
		ToAscii[i] = int(pass.at(i));		
		//cout << ToAscii[i] << endl;		////show value of ascii
		ToAscii[i] += int(key);						//to add value so it changes the character
		converted = converted + char(ToAscii[i]);		//convert previously changed char to string to send to file
	}
	cout << endl;
	return converted;
}