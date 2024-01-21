#include <iostream>
using namespace std;

int main()

{
	string input;
	bool wrongPassord;
	do
	{

		cout << "\n\t Skriv ditt löenord\n\t";
		cin >>input;
		wrongPassord = !(input == "hemlig");
		if (wrongPassord)
			cout << "försöka egen\n";

			
	} while (wrongPassord);
		cout << "\n\tOK nu det är inlogning\n";
}




