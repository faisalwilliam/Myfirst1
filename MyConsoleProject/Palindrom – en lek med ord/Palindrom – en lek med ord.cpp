
// Palindrom en Lek ord .cpp
//En palindrom är en sträng som inte ändras när den läses baklänges.

#include <iostream>
#include <string>
using namespace std;
 // Funktion till chech om indatasträngen är en palindrom
    bool palindrom(char *a) {
		//Allokera minne för att skapa en ny sträng utan blanksteg	
    char *b = new char[strlen(a) + 1];
	int x = 0; //Index för den nya strängen
	// Kopiera tecken från "A" till "B" och utelämna mellanslag

		for (int i = 0; a[i] != '\0'; i++) {

			if (a[i] != ' ') {
				b[x++] = a[i];
			}
		}
		 b[x] = '\0'; //NULL _terminate den nya strängen
		// Kontrollera om den procssed strängen "b" är en palindrom
		int len = strlen(b);
		for (int i = 0; i < len / 2; i++) {
			if (b[i] != b[len - 1 - i]) {
				delete[] b; //Ledigt allallplacerat minne
				return false;  // Inte ett palindrom
			}
		}
		delete[] b;// Ledigt allokerat minne
		return true; // Det är ett palindrom
     }

// huvudfunktion: Startpunkt för programmet	
int main()
	{
	// Förslags lista för användarindata
		const char *suggestions[] = { "radar","deified","level","Hannnah" };
		//Beräkna storleken på förslagsmatrisen
		const int numSuggestions = sizeof(suggestions) / sizeof(suggestions[0]);
		// Kör en oändlig loop för att få användarinmatning och kolla efter palindromer
		while (true) {
			// Buffert för att lagra användarinmatningen
			char str[256];
			cout << "\n\tAnge en str\x84ng och kontrollera palindrome (or 'exit'  quite):";
			cin.getline(str, 256); //Få hela textraden
			// Användaren valde att avsluta programmet
			if (strcmp(str, "exit") == 0) {
				cout << "\n\tAvsluta programmet. H\x84r är n\x86gra palindroms du kan prova:";
				for (int i = 0; i < numSuggestions; ++i) {
					// mata ut palindrom förslagen
					cout << "'" << suggestions[i] << "'";
				}
				cout << "\n";
				break; // Bryt slingan och avsluta programmet
			}
			// Anropa palindromkontrollfunktionen och utgången den result
			if (palindrom(str)) {
				cout << "\n\t\aGrattis! Du har hittat en palindrom =>" << str << endl;
				break; // Palindrom hittad, lämna slingan

			}
			else {
				// Ingen palindrom hittades, uppmana användaren att försöka igen
				cout << "\tStr\x84ng \x84r inte en palindrom. Försök g\x84rna igen." << endl;

			}
		}
		cout<<"\n";
		return 0; // avsluta programmet
		}
	
	
