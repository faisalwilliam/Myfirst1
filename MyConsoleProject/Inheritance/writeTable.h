#pragma once
// writeTable.h
// Skriver till en fil po�ng som lagras i 2D arrayen p
void writeTable(int p[][antalProv], int antElever)
{
	ofstream fileForWrite("Po�ng.txt"); // Filen skapas f�r
	// skrivning
	for (int r = 0; r < antElever; r++)
	{
		for (int k = 0; k < antalProv; k++)
			fileForWrite << p[r][k] << '\t';
		fileForWrite << '\n';
	}
	fileForWrite.close();
}
