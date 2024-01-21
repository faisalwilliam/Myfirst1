

// GuessNEG.cpp
// Gissa tal-spelet med slumptal i dialog
// Kan avslutas även om användaren inte gissar rätt
// Villkor med den logiska operatorn NEGATION (!)
#include <iostream>
using namespace std;
int main()
{
	srand(time(0));
	bool guessOK;
	int guessedNo, secretNo = 1 + rand() % 20;

	do
	{
		cout << "\n\tGissa tal mellan 1 och 20 (Avsluta med 0): ";
		cin >> guessedNo;
		cout << "\n\t";
		if (guessedNo == 0) break; // Bryter do-slingan
		guessOK = (guessedNo == secretNo);
		if (guessOK)
			cout << "\t\aGrattis, du gissade r\x84tt!\n\n";
		if (guessedNo < secretNo) cout << "\tF\x94r litet!\n";
		if (guessedNo > secretNo) cout << "\F\x94r stort!\n";
	
	} while (!guessOK);

	if (guessedNo == 0)
		cout << "\t\nProgr.s hemliga tal var:\t" << secretNo << '\n\n';
}