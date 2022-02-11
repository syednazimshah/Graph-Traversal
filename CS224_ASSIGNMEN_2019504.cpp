#include<iostream>
#include<string>
using namespace std;

int main()
{
	int States, alpha;
	string checkString;

	cout << "Enter the number of states: ";
	cin >> States;
	cout << endl << endl << endl;

	cout << "Enter the number of alphabets: ";
	cin >> alpha;
	cout << endl;
	char alphabetsArray[alpha];
	char statesArray[States];
	cout << "Enter the state names: \n";
	for (int i = 0; i < States; i++)
	{
		cout << "State_NO" << i << ": ";
		cin >> statesArray[i];
	}
	cout << endl << endl;
	cout << "Enter the alphabets you want to use\n";
	for (int j = 0; j < alpha; j++)
	{
		cout << "Alphabet number" << j << ": ";
		cin >> alphabetsArray[j];
	}
	char transTable[States][alpha];
	cout << endl << endl;
	cout << "Enter next state\n";
	for (int x = 0; x < States; x++)
	{
		for (int y = 0; y < alpha; y++)
		{
			cout << "State: " << statesArray[x] << " | Alphabet: " << alphabetsArray[y] << " = ";
			cin >> transTable[x][y];
		}
	}
	char startState;
	char fstate1;
	char fstate2;
	startState = statesArray[0]; 
	fstate1 = statesArray[States - 1];
	fstate2 = statesArray[States - 2];
	cout << "Enter the string that is to be checked: \n";
	cin >> checkString;
	int stringLength = checkString.size();
	int x, y, s = 0;
	int flag = 1;
	for (int s = 0; s < stringLength; s++)
	{
		cout << "Input State \n";
		for (int i = 0; i < States; i++)
		{
			if (statesArray[i] == startState)
			{
				x = i;
				cout << x << endl;
				break;
			}
			else
			{	x = -1;
			}
		}
		cout << "Input String \n";
		for (int i = 0; i < States; i++)
		{
			if (alphabetsArray[i] == checkString[s])
			{
				y = i;
				cout << y << endl;
				break;
			}
			else
			{
				y = -1;
			}
		}
		if (x != -1 && y != -1)
		{
			cout << "Table Output: " << transTable[x][y] << endl;
			startState = transTable[x][y];
		}
	}
	if ((transTable[x][y] == fstate1 || transTable[x][y] == fstate2) && (s == stringLength - 1))
	{cout << "ACCEPTED" << endl;
		flag = 0;
	}
	if (flag != 0)
	{	cout << "REJECTED";
	}
	cout << endl;
}