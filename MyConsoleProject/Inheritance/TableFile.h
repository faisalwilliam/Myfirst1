#pragma once
// TableFile.cpp
// Anropar funktioner som genererar elevernas po�ng i olika
// prov i en tabell, skriver dem till en fil och l�ser fr�n
// filen. Tabellen kan �ndras och uppdateras i filen
#include <iostream>
#include <fstream>
using namespace std;
const int antalProv = 6; // 2D arrayens kolumnantal
#include "setTable.h"
#include "writeTable.h"
#include "readShowTable.h"
#include "updateTable.h"
int main()
{
	const int antalElever = 14; // 2D arrayens radantal
	int poang[antalElever][antalProv];// Definition av 2D array
	char startChange;
	setTable(poang, antalElever); // Arrayen initieras
	writeTable(poang, antalElever); // Skrivs till fil
	cout << antalElever << " elever har gjort " << antalProv
		<< " prov" << " och f�tt f�ljande po�ng:\n\n";
	readShowTable(antalElever); // Arrayen l�ses fr�n
	// fil och skrivs ut
	cout << "\nVill du g�ra �ndringar i tabellen? (J/N): ";
	cin >> startChange;
	if (startChange == 'j' || startChange == 'J');
		updateTable(poang, antalElever); // Arrayen uppdateras
	cout << '\n';
}
