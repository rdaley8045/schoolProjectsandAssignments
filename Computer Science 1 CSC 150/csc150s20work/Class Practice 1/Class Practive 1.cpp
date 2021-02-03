#include<iomanip>
#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>

using namespace std;

int main()
{
	int user_input_1;
	int user_input_2;
	int dice;

	srand((unsigned int)time(0));

	dice = rand()%6+1;

	cout << "Please input 2 numbers: " << endl;
	cout << "First Choice: ";
	cin >> user_input_1;
	cout << "Second Choice: ";
	cin >> user_input_2;

	if (user_input_1 == dice)
	{
		cout << "You won";

	}
	if (user_input_2 == dice) {
		cout << "You won";
	}
	else {
		cout << "You Failed";
	}

	return 0;
}