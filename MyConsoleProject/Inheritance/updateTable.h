#pragma // updateTable.h
// �ndrar v�rden i elevernas po�ngtabell, skriver den uppdat.
// tabellen till en fil, l�ser d�rifr�n och visar p� sk�rmen
#include <iostream>
using namespace std;
void updateTable(int p[][antalProv], int antElever)
{
	int row, column, old;
	char goOnchange;
	do
	{
		cout << "\nVilken elevs po�ng vill du �ndra p�? Elev nr "
			<< "(1-" << antElever << "): ";
		cin >> row;
		cout << "Vilket provs po�ng vill du �ndra p�? Prov nr "
			<< "(1- " << antalProv << "): ";
		cin >> column;
		old = p[row - 1][column - 1]; // Gammalt v�rde spras
		cout << "\n�ndra po�ngen till: ";
		cin >> p[row - 1][column - 1]; // Nytt v�rde l�ses in
		cout << "\nElev " << row << ":s gamla po�ng: " << old
			<< ", nya po�ng: " << p[row - 1][column - 1]
			<< " i prov " << column << "\n\n";
		writeTable(p, antElever); // Uppdaterad array
		// skrivs till fil
		cout << "Vill du forts�tta �ndra? (J/N): ";
		cin >> goOnchange;
	} while (goOnchange == 'j' || goOnchange == 'J');
	cout << "\nUppdaterad tabell:\n\n";
	readShowTable(antElever); // Uppdaterad array
	// l�ses fr�n fil och
} once
