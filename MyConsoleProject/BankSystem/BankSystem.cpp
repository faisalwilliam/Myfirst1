#include <iostream> // Grandläggande I/O_ Åtgärder
#include <string>   // strängtyp och punktioner 
#include <vector>   // Dynamisk matris (vektor)
#include <limits>   // Numeriska gränser
#include <iomanip>  // I/O_manipulatorer som setprecision
using namespace std;
#include "Account.h"
#include "User.h"
#include "ViewAccounts.h"
#include "Bank.h"

// Programmets huvudsakliga startpunkt
int main()
{
	cout << "\n\t Välkommen till InternetBanken!\n";
	Bank bank; // Instansiera ett bank objekt
	bank.run(); // Kör bankprogrammet
	cout << "\n";
	return 0;
	Bank bank; // In

}