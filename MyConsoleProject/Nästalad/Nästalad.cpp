#include <iostream>
using namespace std;

int main() 
{
	
	int guessedNo;
	cout << "\n\tguessed tal mellan 1,10!<\n";
	cin >> guessedNo;
	switch (guessedNo)
	{
	case 1:;
	case 2:;
	case 3:;
	case 4:;
	case 5:;
	case 6:;

		cout << "Gueessad för lite \n";
		break;
	case 7:;
		cout << "Gratis har Guessed Rätt\n";
		break;
	case 8:;
	case 9:;
	case 10:;
		cout << "Guessed för större \n";
		break;

	default:
		cout << "Du har guessed tal utaninterval 1-10\n";
		break;
	}


	




}