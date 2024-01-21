#include "Bank.h"






/*
//#include "Bank.h"
// Visa den inloggade anv�ndarens konton och saldon
void viewAccounts() {
	cout << "\tDina konton och saldo:\n";
	for (const Account& account : users[currentUserIndex].accounts) {
		account.display();
	}
	pressEnterToContinue();
}
// Platsh�llare f�r funktionen f�r �verf�ring av pengar
void transferFunds() {
	// Genomf�rande f�r �verf�ring av medel
}
// Platsh�llare f�r v�xlingsvalutafunktioner
void exchangeCurrency() {
	// Implementering f�r valutav�xling
}
// Verktygsfunktion f�r att v�nta p� att anv�ndaren trycker p� enter
void pressEnterToContinue() {
	cout << "\nTryck p� enter f�r att komma tillbaka till huvudmenyn.";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
}
// Hantera utloggning och �terst�llningstillst�nd f�r anv�ndare
void logout() {
	currentUserIndex = -1;
	cout << "\tDu har loggats ut.\n\n";
}
*/

void viewAccounts() {
	cout << "\tDina konton och saldo:\n";
	for (const auto& account : users[currentUserIndex].accounts) {
		cout << "\tKontonummer: " << account.getNumber() << " Saldo: " << account.getBalance() << " kr\n";
	}
	pressEnterToContinue();
}
void transferFunds() {
	int fromAccountIndex, toAccountIndex;
	double amount;
	cout << "\tAnge kontoindex att �verf�ra fr�n: ";
	cin >> fromAccountIndex;
	cout << "\tAnge kontoindex att �verf�ra till: ";
	cin >> toAccountIndex;
	cout << "\tAnge belopp att �verf�ra: ";
	cin >> amount;
	auto& fromAccount = users[currentUserIndex].accounts[fromAccountIndex];
	auto& toAccount = users[currentUserIndex].accounts[toAccountIndex];
	fromAccount.withdraw(amount);
	toAccount.deposit(amount);
	cout << "\t�verf�ring genomf�rd.\n";
	pressEnterToContinue();
}
void exchangeCurrency() {
	// Din kod f�r valutav�xling h�r
}
void pressEnterToContinue() {
	cout << "\tTryck p� enter f�r att komma tillbaka till huvudmenyn.";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cin.get();
}
}
