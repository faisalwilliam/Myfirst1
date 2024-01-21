
// Palindrom en Lek ord .cpp
//En palindrom �r en str�ng som inte �ndras n�r den l�ses bakl�nges.

#include <iostream>
#include <string>
using namespace std;
 // Funktion till chech om indatastr�ngen �r en palindrom
    bool palindrom(char *a) {
		//Allokera minne f�r att skapa en ny str�ng utan blanksteg	
    char *b = new char[strlen(a) + 1];
	int x = 0; //Index f�r den nya str�ngen
	// Kopiera tecken fr�n "A" till "B" och utel�mna mellanslag

		for (int i = 0; a[i] != '\0'; i++) {

			if (a[i] != ' ') {
				b[x++] = a[i];
			}
		}
		 b[x] = '\0'; //NULL _terminate den nya str�ngen
		// Kontrollera om den procssed str�ngen "b" �r en palindrom
		int len = strlen(b);
		for (int i = 0; i < len / 2; i++) {
			if (b[i] != b[len - 1 - i]) {
				delete[] b; //Ledigt allallplacerat minne
				return false;  // Inte ett palindrom
			}
		}
		delete[] b;// Ledigt allokerat minne
		return true; // Det �r ett palindrom
     }

// huvudfunktion: Startpunkt f�r programmet	
int main()
	{
	// F�rslags lista f�r anv�ndarindata
		const char *suggestions[] = { "radar","deified","level","Hannnah" };
		//Ber�kna storleken p� f�rslagsmatrisen
		const int numSuggestions = sizeof(suggestions) / sizeof(suggestions[0]);
		// K�r en o�ndlig loop f�r att f� anv�ndarinmatning och kolla efter palindromer
		while (true) {
			// Buffert f�r att lagra anv�ndarinmatningen
			char str[256];
			cout << "\n\tAnge en str\x84ng och kontrollera palindrome (or 'exit'  quite):";
			cin.getline(str, 256); //F� hela textraden
			// Anv�ndaren valde att avsluta programmet
			if (strcmp(str, "exit") == 0) {
				cout << "\n\tAvsluta programmet. H\x84r �r n\x86gra palindroms du kan prova:";
				for (int i = 0; i < numSuggestions; ++i) {
					// mata ut palindrom f�rslagen
					cout << "'" << suggestions[i] << "'";
				}
				cout << "\n";
				break; // Bryt slingan och avsluta programmet
			}
			// Anropa palindromkontrollfunktionen och utg�ngen den result
			if (palindrom(str)) {
				cout << "\n\t\aGrattis! Du har hittat en palindrom =>" << str << endl;
				break; // Palindrom hittad, l�mna slingan

			}
			else {
				// Ingen palindrom hittades, uppmana anv�ndaren att f�rs�ka igen
				cout << "\tStr\x84ng \x84r inte en palindrom. F�rs�k g\x84rna igen." << endl;

			}
		}
		cout<<"\n";
		return 0; // avsluta programmet
		}
	
	
