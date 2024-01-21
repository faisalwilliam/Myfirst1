// Bankkassen innehåller den huvudsaklga loigken för användare ovh deras interaktioner

#include "ViewAccounts.h"
#include "User.h"
class Bank {
private:
	// Variabler och funktioner för private medlemmare
	vector<User> users; // Lista över användare
	int currentUserIndex; // Index över inloggad
	// Displayu the main menu options to the user
	void displayMainMenu()
	{
		cout << "\n\tVälkommen till huvudmenyn, vad vill du göra?\n"
			<< "\t 1. Se dina konton och saldo\n"
			<< "\t 2. Överföring mellan konton\n"
			<< "\t 3. Växla pengar\n "
			<< "\t 4. Logga ut\n";


	}
	// kontrollera om den angivna PIN-Kodem matcher användaren PIN-kod
	bool verifyPin(const User& user, int pin) {
		return user.pin == pin;
	}
	// Hantera inloggningsförsök för användare
	void handleLogin()
	{
		string username;
		int pin;
		int attempts = 0;
		bool isAutentiserad = false;
		// Tilllåt upp till 3 inloggningsförsöka
		while (!isAutentiserad && attempts < 3)
			// Begär autentiserads uppgifter
			cout << "\tAnge ditt användarnamn: ";
		cin >> username;
		cout << "\tAnge din pinkod: ";
		cin >> pin;
		// Kontrollera mot befinliga användare
		for (size_t i = 0; i < users.size(); i++) {
			if (users[i].username == username && verifyPin(users[i], pin)) {
				currentUserIndex = i;
				isAutentiserad = true;
				break;
			}
		}
		// Om den in autentiseras ökar du räknaren för ökningsförsök
		if (!isAutentiserad) {
			cout << "\tFel användarenamn eller pinkod, försök igen.\n";
			++attempts;
		}
	}
	// Om för många misloggade försök avsluta programmet
	if (attempts >= 3) {
		cout << "\tFör många försök. Programmet avslutas.\n";
		exit(0);
	}
}
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
	public
		// Constructör of Bank initierar vissa demoanvändare och konton
		Bank() : currentUserIndex(-1) {
		users.push_back(User("amir", 2023, { Accopunt("\tLöneKonto", 10000.50,Account("\tSparkont", 1500.75) }));
		users.push_back(User("faisal", 1234, { Accopunt("\tLöneKonto", 110000.50,Account("\tSparkont", 1600.75) }));
		users.push_back(User("aish", 1985, { Accopunt("\tLöneKonto", 120000.50,Account("\tSparkont", 1700.75) }));
		users.push_back(User("safa", 2012, { Accopunt("\tLöneKonto", 130000.50,Account("\tSparkont", 1800.75) }));
		users.push_back(User("anfal", 2014, { Accopunt("\tLöneKonto", 140000.50,Account("\tSparkont", 1900.75) }));
		// Lägg till flera användare efter behov
	}
	// Köra huvud bank programslingan
	void run() {
		while (true) {
			handleLogin();  // Hantera användarinloggning
			bool isRunning = true;
			// När användaren är inloggad
			while (isRunning) {
				displayMainMenu(); // Visa huvudmeny
				int choice;
				cin >> choice;
				// Utför vald åtgärd
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
					cout << "\tOgiltigt val, försök igen.\n";

				}
			}
		}
	}
	

};



