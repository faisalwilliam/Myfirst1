// setTable.h
// Tilldelar slumpvärden till 2D arrayen p genom att anropa
// den externlagrade funktionen myRand
// 2D array som parameter i en funktion
#include <ctime>
#include "myRand.h"
void setTable(int p[][antalProv], int antElever)
{
	srand(time(0));
	for (int r = 0; r < antElever; r++)
		for (int k = 0; k < antalProv; k++)
				p[r][k] = myRand(10, 100);
}
