#pragma once
// writeTable.h
// Skriver till en fil poäng som lagras i 2D arrayen p
void writeTable(int p[][antalProv], int antElever)
{
	ofstream fileForWrite("Poäng.txt"); // Filen skapas för
	// skrivning
	for (int r = 0; r < antElever; r++)
	{
		for (int k = 0; k < antalProv; k++)
			fileForWrite << p[r][k] << '\t';
		fileForWrite << '\n';
	}
	fileForWrite.close();
}
