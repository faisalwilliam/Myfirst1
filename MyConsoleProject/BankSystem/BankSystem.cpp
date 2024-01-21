#include <iostream> // Grandl�ggande I/O_ �tg�rder
#include <string>   // str�ngtyp och punktioner 
#include <vector>   // Dynamisk matris (vektor)
#include <limits>   // Numeriska gr�nser
#include <iomanip>  // I/O_manipulatorer som setprecision
using namespace std;
#include "Account.h"
#include "User.h"
#include "ViewAccounts.h"
#include "Bank.h"

// Programmets huvudsakliga startpunkt
int main()
{
	cout << "\n\t V�lkommen till InternetBanken!\n";
	Bank bank; // Instansiera ett bank objekt
	bank.run(); // K�r bankprogrammet
	cout << "\n";
	return 0;
	Bank bank; // In

}