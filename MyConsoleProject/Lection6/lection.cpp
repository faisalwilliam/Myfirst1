

   #include <iostream>  // Grundläggande I/O-åtgärder
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
public:
	// Constructor of Bank initierar vissa demoanvändare och konton
	Bank() : currentUserIndex(-1) {
		// Initiera med vissa användare och konton
		users.push_back(User("faisal", 1234, { Account("\tLönekonto", 10000.50), Account("\tSparkonto", 15000.75) }));
		users.push_back(User("aisha", 1985, { Account("\tLönekonto", 12000.00) }));
		users.push_back(User("amir", 2023, { Account("\tLöneKonto",13000.00) }));
		users.push_back(User("anfal", 2014, { Account("\tLöneKonto",14000.00) }));
		users.push_back(User("safa", 2012, { Account("\tLöneKonto",15000.00) }));
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
	cout<<"\n";
	
	return 0;
Bank bank; // In