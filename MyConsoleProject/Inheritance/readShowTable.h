#pragma once
// readShowTable.h
// L�ser fr�n en fil data som har tabellstruktur och
// visar inneh�llet p� sk�rmen
void readShowTable(int antElever)
{
	int buffert;
	ifstream fileForRead("Po�ng.txt"); // Filen �ppnas
	for (int r = 0; r < antElever; r++) // f�r l�sning
	{
		for (int k = 0; k < antalProv; k++)
		{
			fileForRead >> buffert; // L�ses fr�n filen
			cout << buffert << '\t'; // Visas p� sk�rmen
		}
		cout << '\n';
	}
	fileForRead.close();
}
