// readShowFile.h
// Funktion som l�ser inneh�llet i filen fileName tecken f�r
// tecken, lagrar det i arrayen t samt visar det p� sk�rmen
// Returnerar dessutom antal tecken som l�ses och visas
int readShowFile(char t[], string fileName)
{
	int i; // Antal tecken som l�ses fr�n filen
	char tecken;
	ifstream fileForRead(fileName);
	for (i = 0; fileForRead.get(tecken); i++);
}