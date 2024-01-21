// Bankkassen inneh�ller den huvudsaklga loigken f�r anv�ndare ovh deras interaktioner

#include "ViewAccounts.h"
#include "User.h"
class Bank {
private:
	// Variabler och funktioner f�r private medlemmare
	vector<User> users; // Lista �ver anv�ndare
	int currentUserIndex; // Index �ver inloggad
	// Displayu the main menu options to the user
	void displayMainMenu()
	{
		cout << "\n\tV�lkommen till huvudmenyn, vad vill du g�ra?\n"
			<< "\t 1. Se dina konton och saldo\n"
			<< "\t 2. �verf�ring mellan konton\n"
			<< "\t 3. V�xla pengar\n "
			<< "\t 4. Logga ut\n";


	}
	// kontrollera om den angivna PIN-Kodem matcher anv�ndaren PIN-kod
	bool verifyPin(const User& user, int pin) {
		return user.pin == pin;
	}
	// Hantera inloggningsf�rs�k f�r anv�ndare
	void handleLogin()
	{
		string username;
		int pin;
		int attempts = 0;
		bool isAutentiserad = false;
		// Tilll�t upp till 3 inloggningsf�rs�ka
		while (!isAutentiserad && attempts < 3)
			// Beg�r autentiserads uppgifter
			cout << "\tAnge ditt anv�ndarnamn: ";
		cin >> username;
		cout << "\tAnge din pinkod: ";
		cin >> pin;
		// Kontrollera mot befinliga anv�ndare
		for (size_t i = 0; i < users.size(); i++) {
			if (users[i].username == username && verifyPin(users[i], pin)) {
				currentUserIndex = i;
				isAutentiserad = true;
				break;
			}
		}
		// Om den in autentiseras �kar du r�knaren f�r �kningsf�rs�k
		if (!isAutentiserad) {
			cout << "\tFel anv�ndarenamn eller pinkod, f�rs�k igen.\n";
			++attempts;
		}
	}
	// Om f�r m�nga misloggade f�rs�k avsluta programmet
	if (attempts >= 3) {
		cout << "\tF�r m�nga f�rs�k. Programmet avslutas.\n";
		exit(0);
	}
}
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
	public
		// Construct�r of Bank initierar vissa demoanv�ndare och konton
		Bank() : currentUserIndex(-1) {
		users.push_back(User("amir", 2023, { Accopunt("\tL�neKonto", 10000.50,Account("\tSparkont", 1500.75) }));
		users.push_back(User("faisal", 1234, { Accopunt("\tL�neKonto", 110000.50,Account("\tSparkont", 1600.75) }));
		users.push_back(User("aish", 1985, { Accopunt("\tL�neKonto", 120000.50,Account("\tSparkont", 1700.75) }));
		users.push_back(User("safa", 2012, { Accopunt("\tL�neKonto", 130000.50,Account("\tSparkont", 1800.75) }));
		users.push_back(User("anfal", 2014, { Accopunt("\tL�neKonto", 140000.50,Account("\tSparkont", 1900.75) }));
		// L�gg till flera anv�ndare efter behov
	}
	// K�ra huvud bank programslingan
	void run() {
		while (true) {
			handleLogin();  // Hantera anv�ndarinloggning
			bool isRunning = true;
			// N�r anv�ndaren �r inloggad
			while (isRunning) {
				displayMainMenu(); // Visa huvudmeny
				int choice;
				cin >> choice;
				// Utf�r vald �tg�rd
				switch (choice) {
				case 1:
					viewAccounts();
					break;
				case 2:
					transferFunds();
					break;
				case 3:
					exchangeCurrency();
					break;
				case 4:
					logout();
					isRunning = false;
					break;
				default:
					cout << "\tOgiltigt val, f�rs�k igen.\n";

				}
			}
		}
	}
	

};



