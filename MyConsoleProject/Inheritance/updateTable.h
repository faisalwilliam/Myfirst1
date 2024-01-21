#pragma // updateTable.h
// Ändrar värden i elevernas poängtabell, skriver den uppdat.
// tabellen till en fil, läser därifrån och visar på skärmen
#include <iostream>
using namespace std;
void updateTable(int p[][antalProv], int antElever)
{
	int row, column, old;
	char goOnchange;
	do
	{
		cout << "\nVilken elevs poäng vill du ändra på? Elev nr "
			<< "(1-" << antElever << "): ";
		cin >> row;
		cout << "Vilket provs poäng vill du ändra på? Prov nr "
			<< "(1- " << antalProv << "): ";
		cin >> column;
		old = p[row - 1][column - 1]; // Gammalt värde spras
		cout << "\nÄndra poängen till: ";
		cin >> p[row - 1][column - 1]; // Nytt värde läses in
		cout << "\nElev " << row << ":s gamla poäng: " << old
			<< ", nya poäng: " << p[row - 1][column - 1]
			<< " i prov " << column << "\n\n";
		writeTable(p, antElever); // Uppdaterad array
		// skrivs till fil
		cout << "Vill du fortsätta ändra? (J/N): ";
		cin >> goOnchange;
	} while (goOnchange == 'j' || goOnchange == 'J');
	cout << "\nUppdaterad tabell:\n\n";
	readShowTable(antElever); // Uppdaterad array
	// läses från fil och
} once
