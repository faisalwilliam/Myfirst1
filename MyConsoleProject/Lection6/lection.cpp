

   #include <iostream>  // Grundl�ggande I/O-�tg�rder
   #include <string>   // Str�ngtyp och funktioner
   #include <vector>   //Dynamisk matris (vektor)
   #include <limits>   // Numeriska gr�nser
   #include <iomanip>  // I/O-manipulatorer som setprecision
   using namespace std;
    // Klassen Account representerar ett bankkonto med ett namn och saldo
    class Account{
    public:
	// Offentliga medlems variabler
	string name;
	float balance;
	//Konstrukt�ren initierar kontot med ett namn och saldo
	Account(string name, float balance) : name(name), balance(balance) {}
	// Visa kontonamn och saldo med fast precision for currency
	void display() const {
		cout << name << ": " << fixed << setprecision(2) << balance << " SEK\n";
	}
   };
     
//Klassen User representerar en bankanv�ndare med ett anv�ndarnamn, en PIN - kod och flera konton  
 class User{
 public:
	string username;
	int pin;
	vector<Account> accounts;
	// Konstruktorn initierar anv�ndaren med ett anv�ndarnamn, en PIN-kod och deras konton
	User(string username, int pin, vector<Account> accounts)
		: username(username), pin(pin), accounts(accounts) {}
     };
   // Bankklassen inneh�ller den huvudsakliga logiken f�r anv�ndare och deras interaktioner
    class Bank {
private:
	// Variabler och funktioner f�r privata medlemmar
	vector<User> users; // Lista �ver anv�ndare
	int currentUserIndex;    // Index �ver inloggad anv�ndare
	//Display the main menu options to the user
	void displayMainMenu() {
		cout << "\n\tV�lkommen till huvudmenyn, vad vill du g�ra?\n"
	
			}
		}
		// Om f�r m�nga misslyckade f�rs�k, avsluta programmet
		if (attempts >= 3) {
			cout << "\tF�r m�nga f�rs�k. Programmet avslutas.\n";
			exit(0);
		}
	}
	// Visa den inloggade anv�ndarens konton och saldon
	void viewAccounts() {
		cout << "\tDina konton och saldo:\n";
		for (const Account& account: users[currentUserIndex].accounts) {
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
public:
	// Constructor of Bank initierar vissa demoanv�ndare och konton
	Bank() : currentUserIndex(-1) {
		// Initiera med vissa anv�ndare och konton
		users.push_back(User("faisal", 1234, { Account("\tL�nekonto", 10000.50), Account("\tSparkonto", 15000.75) }));
		users.push_back(User("aisha", 1985, { Account("\tL�nekonto", 12000.00) }));
		users.push_back(User("amir", 2023, { Account("\tL�neKonto",13000.00) }));
		users.push_back(User("anfal", 2014, { Account("\tL�neKonto",14000.00) }));
		users.push_back(User("safa", 2012, { Account("\tL�neKonto",15000.00) }));
		// L�gg till fler anv�ndare efter behov
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
// Programmets huvudsakliga startpunkt
int main() {

	cout << "\n\tV�lkommen till Internetbanken!\n";
	Bank bank; // Instansiera ett bank objekt
	bank.run(); // K�r bankprogrammet
	cout<<"\n";
	
	return 0;
Bank bank; // In