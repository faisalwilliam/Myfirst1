// readShowFile.h
// Funktion som läser innehållet i filen fileName tecken för
// tecken, lagrar det i arrayen t samt visar det på skärmen
// Returnerar dessutom antal tecken som läses och visas
int readShowFile(char t[], string fileName)
{
	int i; // Antal tecken som läses från filen
	char tecken;
	ifstream fileForRead(fileName);
	for (i = 0; fileForRead.get(tecken); i++);
}