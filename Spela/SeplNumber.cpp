#include <iostream>
using namespace std;

int main()

{
	string input;
	bool wrongPassord;
	do
	{

		cout << "\n\t Skriv ditt l�enord\n\t";
		cin >>input;
		wrongPassord = !(input == "hemlig");
		if (wrongPassord)
			cout << "f�rs�ka egen\n";

			
	} while (wrongPassord);
		cout << "\n\tOK nu det �r inlogning\n";
}




