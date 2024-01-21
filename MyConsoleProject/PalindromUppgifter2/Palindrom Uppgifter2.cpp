
// Palindrom en Lek ord .cpp
//En palindrom �r en str�ng som inte �ndras n�r den l�ses bakl�nges.

#include <iostream>
using namespace std;

// Function som avg�r om en str�ng �r en palindrom
bool palindrom(char *a)
{
	int length = strlen(a); // Ber�knar p� a str�ngen
	for (int i = 0; i < length / 2; ++i) {
		// Om tecknen int matchar i fram - och baksidan, �r det int en palindrom
		if (a[i] != a[length - i - 1])
			return false;
    }
	 // Om alla tecken matcken �r str�ngen  en palindrom
	return true;
}
 // funktion som tar bort alla mellanslag fr�n str�ngen
void removeSpaces(char* original, char* withoutSpaces)
{
	while (*original != '\0') { // Loop s� l�nge slutet av str�ngen inte n�tts
		if (*original != ' ') { // Kopiera int �ver mellanslag
			*withoutSpaces = *original;
			++withoutSpaces;

		}
		++original; // Flytta till n�sta tecken i den orginala str�gen
	}
	*withoutSpaces = '\0'; // L�gg till en nollterminatotr vid slutet av den nya str�ngen
}
int main()
{
	const int size = 100;
	char str[size];// str�ngen anv�ndaren matar in
	char strWithoutSpaces[size];// str�ngen utan mellanslag
	while (true) {
		cout << "\n\tMata in Str\x84ng:";
		cin.getline(str, size); // L�s en rad fr�n anv�ndaren
		removeSpaces(str, strWithoutSpaces);// Ta bort mellanslag
		// Kontrollera om manipulerade str�ngen �r en palindrom
		if (palindrom(strWithoutSpaces)) {
			cout << "\n\t\aGrattis! En palindrom hittades:\n\n";
			break; // Avsluta loop om en palindrom hittas
		}
		else {
			char choice;
			cout << "\n\tInte ett palindrom. Vill du f\x94rs\x94ka igen?(Y/N):";
			cin >> choice;
			cin.ignore(); // F�r att ignorera newlinen efter valet 
			if (choice == 'N' || choice == 'n') {
				// Ge n�gra exempel p� palindromer om anv�ndaren v�ljetr att int f�rska igen
				cout << "\t\n H\x84r \x84r n\x86gra palindroms du kanske gillar: radar,level,civic,rotor,Hannah:"<< endl;
				break; // Avsluta loop om anv�ndaren inte vill forts�tta
               
			 }
		
		}
	 }cout <<"\t";
	return 0;
}


