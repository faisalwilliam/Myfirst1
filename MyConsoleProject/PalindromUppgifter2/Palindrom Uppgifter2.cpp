
// Palindrom en Lek ord .cpp
//En palindrom är en sträng som inte ändras när den läses baklänges.

#include <iostream>
using namespace std;

// Function som avgör om en sträng är en palindrom
bool palindrom(char *a)
{
	int length = strlen(a); // Beräknar på a strängen
	for (int i = 0; i < length / 2; ++i) {
		// Om tecknen int matchar i fram - och baksidan, är det int en palindrom
		if (a[i] != a[length - i - 1])
			return false;
    }
	 // Om alla tecken matcken är strängen  en palindrom
	return true;
}
 // funktion som tar bort alla mellanslag från strängen
void removeSpaces(char* original, char* withoutSpaces)
{
	while (*original != '\0') { // Loop så länge slutet av strängen inte nåtts
		if (*original != ' ') { // Kopiera int över mellanslag
			*withoutSpaces = *original;
			++withoutSpaces;

		}
		++original; // Flytta till nästa tecken i den orginala strägen
	}
	*withoutSpaces = '\0'; // Lägg till en nollterminatotr vid slutet av den nya strängen
}
int main()
{
	const int size = 100;
	char str[size];// strängen användaren matar in
	char strWithoutSpaces[size];// strängen utan mellanslag
	while (true) {
		cout << "\n\tMata in Str\x84ng:";
		cin.getline(str, size); // Läs en rad från användaren
		removeSpaces(str, strWithoutSpaces);// Ta bort mellanslag
		// Kontrollera om manipulerade strängen är en palindrom
		if (palindrom(strWithoutSpaces)) {
			cout << "\n\t\aGrattis! En palindrom hittades:\n\n";
			break; // Avsluta loop om en palindrom hittas
		}
		else {
			char choice;
			cout << "\n\tInte ett palindrom. Vill du f\x94rs\x94ka igen?(Y/N):";
			cin >> choice;
			cin.ignore(); // För att ignorera newlinen efter valet 
			if (choice == 'N' || choice == 'n') {
				// Ge några exempel på palindromer om användaren väljetr att int förska igen
				cout << "\t\n H\x84r \x84r n\x86gra palindroms du kanske gillar: radar,level,civic,rotor,Hannah:"<< endl;
				break; // Avsluta loop om användaren inte vill fortsätta
               
			 }
		
		}
	 }cout <<"\t";
	return 0;
}


