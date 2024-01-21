#include "Bank.h"






/*
//#include "Bank.h"
// Visa den inloggade användarens konton och saldon
void viewAccounts() {
	cout << "\tDina konton och saldo:\n";
	for (const Account& account : users[currentUserIndex].accounts) {
		account.display();
	}
	pressEnterToContinue();
}
// Platshållare för funktionen för överföring av pengar
void transferFunds() {
	// Genomförande för överföring av medel
}
// Platshållare för växlingsvalutafunktioner
void exchangeCurrency() {
	// Implementering för valutaväxling
}
// Verktygsfunktion för att vänta på att användaren trycker på enter
void pressEnterToContinue() {
	cout << "\nTryck på enter för att komma tillbaka till huvudmenyn.";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
}
// Hantera utloggning och återställningstillstånd för användare
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
	cout << "\tAnge kontoindex att överföra från: ";
	cin >> fromAccountIndex;
	cout << "\tAnge kontoindex att överföra till: ";
	cin >> toAccountIndex;
	cout << "\tAnge belopp att överföra: ";
	cin >> amount;
	auto& fromAccount = users[currentUserIndex].accounts[fromAccountIndex];
	auto& toAccount = users[currentUserIndex].accounts[toAccountIndex];
	fromAccount.withdraw(amount);
	toAccount.deposit(amount);
	cout << "\tÖverföring genomförd.\n";
	pressEnterToContinue();
}
void exchangeCurrency() {
	// Din kod för valutaväxling här
}
void pressEnterToContinue() {
	cout << "\tTryck på enter för att komma tillbaka till huvudmenyn.";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cin.get();
}
}
