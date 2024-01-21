#pragma once
// readShowTable.h
// Läser från en fil data som har tabellstruktur och
// visar innehållet på skärmen
void readShowTable(int antElever)
{
	int buffert;
	ifstream fileForRead("Poäng.txt"); // Filen öppnas
	for (int r = 0; r < antElever; r++) // för läsning
	{
		for (int k = 0; k < antalProv; k++)
		{
			fileForRead >> buffert; // Läses från filen
			cout << buffert << '\t'; // Visas på skärmen
		}
		cout << '\n';
	}
	fileForRead.close();
}
