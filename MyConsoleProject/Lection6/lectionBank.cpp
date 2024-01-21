

   #include <iostream> // Grundläggande I/O-åtgärder
   #include <string>   // Strängtyp och funktioner
   #include <vector>   //Dynamisk matris (vektor)
   #include <limits>   // Numeriska gränser
   #include <iomanip>  // I/O-manipulatorer som setprecision
   using namespace std;
    // Klassen Account representerar ett bankkonto med ett namn och saldo
    class Account{
    public:
	// Offentliga medlems variabler
	string name;
	float balance;
	//Konstruktören initierar kontot med ett namn och saldo
	Account(string name, float balance) : name(name), balance(balance) {}
	// Visa kontonamn och saldo med fast precision for currency
	void display() const {
		cout << name << ": " << fixed << setprecision(2) << balance << " SEK\n";
	}
   };
     
//Klassen User representerar en bankanvändare med ett användarnamn, en PIN - kod och flera konton  
 class User{
 public:
	string username;
	int pin;
	vector<Account> accounts;
	// Konstruktorn initierar användaren med ett användarnamn, en PIN-kod och deras konton
	User(string username, int pin, vector<Account> accounts)
		: username(username), pin(pin), accounts(accounts) {}
     };
   // Bankklassen innehåller den huvudsakliga logiken för användare och deras interaktioner
    class Bank {
private:
	// Variabler och funktioner för privata medlemmar
	vector<User> users; // Lista över användare
	int currentUserIndex;    // Index över inloggad användare
	//Display the main menu options to the user
	void displayMainMenu() {
		cout << "\n\tVälkommen till huvudmenyn, vad vill du göra?\n"
			<< "\t1. Se dina konton och saldo\n"
			<< "\t2. Överföring mellan konton\n"
			<< "\t3. Växla pengar\n"
			<< "\t4. Logga ut\n";
	}
	// Kontrollera om den angivna PIN-koden matchar användarens PIN-kod
	bool verifyPin(const User& user, int pin) {
		return user.pin == pin;
	}
	// Hantera inloggningsförsök för användare
	void handleLogin() {
		string username;
		int pin;
		int attempts = 0;
		bool isAutentiserad = false;
		// Tillåt upp till 3 inloggningsförsök
		while (!isAutentiserad && attempts < 3) {
			// Begär autentiserings uppgifter
			cout << "\tAnge ditt användarnamn: ";
			cin >> username;
			cout << "\tAnge din pinkod: ";
			cin >> pin;
			// Kontrollera mot befintliga användare
			for (size_t i = 0; i < users.size(); i++) {
				if (users[i].username == username && verifyPin(users[i], pin)) {
					currentUserIndex = i;
				isAutentiserad = true;
					break;
				}
			}
			// Om den inte autentiseras ökar du räknaren för ökningsförsök
			if (!isAutentiserad) {
				cout << "\tFel användarnamn eller pinkod, försök igen.\n";
				++attempts;
			}
		}
		// Om för många misslyckade försök, avsluta programmet
		if (attempts >= 3) {
			cout << "\tFör många försök. Programmet avslutas.\n";
			exit(0);
		}
	}
	// Visa den inloggade användarens konton och saldon
	void viewAccounts() {
		cout << "\tDina konton och saldo:\n";
		for (const Account& account: users[currentUserIndex].accounts) {
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
	// Constructor of Bank initierar vissa demoanvändare och konton
	Bank() : currentUserIndex(-1) {
		// Initiera med vissa användare och konton
		users.push_back(User("Faisal", 1234, { Account("\tLönekonto", 10000.50), Account("\tSparkonto", 15000.75) }));
		users.push_back(User("Matar", 2345, { Account("\tLönekonto", 12000.00) }));
		users.push_back(User("Amir", 2023, { Account("\tLöneKonto",13000.00) }));
		// Lägg till fler användare efter behov
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
// Programmets huvudsakliga startpunkt
int main() {

	cout << "\n\tVälkommen till Internetbanken!\n";
	Bank bank; // Instansiera ett bank objekt
	bank.run(); // Kör bankprogrammet
	
	return 0;
}