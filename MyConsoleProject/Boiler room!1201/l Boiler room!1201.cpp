

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip>
using namespace std;
class Account {
public:
	string name;
	float balance;
	Account(string name, float balance) : name(name), balance(balance) {}
	float getBalance() const {
		return balance;
	}
	string getNumber() const {
		return name;
	}
	void display() const {
		cout << name << ": " << fixed << setprecision(2) << balance << " SEK\n";
	}
	void deposit(float amount) {
		balance += amount;
	}
	void withdraw(float amount) {
		balance -= amount;
	}
};
class User {
public:
	string username;
	int pin;
	vector<Account> accounts;
	User(string username, int pin, vector<Account> accounts)
		: username(username), pin(pin), accounts(accounts) {}
};
class Bank {
private:
	vector<User> users;
	int currentUserIndex;
	void pressEnterToContinue() {
		cout << "\nTryck p� [Enter] f�r att forts�tta";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.get();
	}

	void displayMainMenu() {
		cout << "\n\tV�lkommen till huvudmenyn, vad vill du g�ra?\n"
			<< "\t1. Se dina konton och saldo\n"
			<< "\t2. �verf�ring mellan konton\n"
			<< "\t3. V�xla pengar\n"
			<< "\t4. Logga ut\n";
	}
	bool verifyPin(const User& user, int pin) {
		return user.pin == pin;
	}
	void handleLogin() {
		string username;
		int pin;
		int attempts = 0;
		bool isAuthenticated = false;
		while (!isAuthenticated && attempts < 3) {
			cout << "\tAnge ditt anv�ndarnamn: ";
			cin >> username;
			cout << "\tAnge din pinkod: ";
			cin >> pin;
			for (size_t i = 0; i < users.size(); i++) {
				if (users[i].username == username && verifyPin(users[i], pin)) {
					currentUserIndex = i;
					isAuthenticated = true;
					break;
				}
			}
			if (!isAuthenticated) {
				cout << "\tFel anv�ndarnamn eller pinkod, f�rs�k igen.\n";
				++attempts;
			}
		}
		if (attempts >= 3) {
			cout << "\tF�r m�nga f�rs�k. Programmet avslutas.\n";
			exit(0);
		}
	}
	void viewAccounts() {
		cout << "\tDina konton och saldo:\n";
		for (const auto& account : users[currentUserIndex].accounts) {
			account.display();
		}
		pressEnterToContinue();
	}
	void transferFunds() {
		int fromAccountIndex, toAccountIndex;
		float amount;
		cout << "\tAnge kontoindex att �verf�ra fr�n: ";
		cin >> fromAccountIndex;
		cout << "\tAnge kontoindex att �verf�ra till: ";
		cin >> toAccountIndex;
		cout << "\tAnge belopp att �verf�ra: ";
		cin >> amount;
		if (fromAccountIndex >= 0 && fromAccountIndex < users[currentUserIndex].accounts.size() &&
			toAccountIndex >= 0 && toAccountIndex < users[currentUserIndex].accounts.size()) {
			auto& fromAccount = users[currentUserIndex].accounts[fromAccountIndex];
			auto& toAccount = users[currentUserIndex].accounts[toAccountIndex];
			if (amount <= fromAccount.getBalance() && amount > 0) {
				fromAccount.withdraw(amount);
				toAccount.deposit(amount);
				cout << "\t�verf�ring genomf�rd.\n";
			}
			else {
				cout << "\tOtillr�ckliga medel eller ogiltigt belopp.\n";
			}
		}
		else {
			cout << "\tOgiltigt kontoindex.\n";
		}
		pressEnterToContinue();
	}
	void exchangeCurrency() {
		int accountIndex;
		float amount;
		float exchangeRate;
		string fromCurrency, toCurrency;
		cout << "\tAnge kontoindex att v�xla fr�n: ";
		cin >> accountIndex;
		cout << "\tAnge valutan du vill v�xla fr�n (SEK, USD, EUR): ";
		cin >> fromCurrency;
		cout << "\tAnge valutan du vill v�xla till (SEK, USD, EUR): ";
		cin >> toCurrency;
		cout << "\tAnge belopp att v�xla: ";
		cin >> amount;
		cout << "\tAnge v�xelkurs: ";
		cin >> exchangeRate;
		if (accountIndex >= 0 && accountIndex < users[currentUserIndex].accounts.size()) {
			auto& account = users[currentUserIndex].accounts[accountIndex];
			if (fromCurrency == toCurrency) {
				cout << "\tDu kan inte v�xla till samma valuta.\n";
			}
			else if (amount <= account.getBalance() && amount > 0) {
				float exchangedAmount = amount * exchangeRate;
				account.withdraw(amount);
				cout << "\t" << setprecision(2) << fixed << amount << " " << fromCurrency
					<< " har v�xlats till " << exchangedAmount << " " << toCurrency << "\n";
				// NOTE: Exchanged currency is not added to any account as per current requirement
			}
			else {
				cout << "\tOtillr�ckliga medel eller ogiltigt belopp.\n";
			}
		}
		else {
			cout << "\tOgiltigt kontoindex.\n";
		}
		pressEnterToContinue();
	}

	void logout() {
		currentUserIndex = -1;
		cout << "\tDu har loggats ut.\n\n";
	}
public:
	Bank() : currentUserIndex(-1) {
		users.push_back(User("Faisal", 1234, { Account("L�nekonto", 10000.50), Account("Sparkonto", 15000.75) }));
		users.push_back(User("Matar", 2345, { Account("L�nekonto", 12000.00), Account("Sparkonto", 16000.75) }));
		users.push_back(User("Amir", 2023, { Account("L�neKonto", 13000.00), Account("Sparkonto", 17000.75) }));
	}
	void run() {
		while (true) {
			handleLogin();
			bool isRunning = true;
			while (isRunning) {
				displayMainMenu();
				int choice;
				cin >> choice;
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
int main() {
	cout << "\n\tV�lkommen till Internetbanken!\n";
	Bank bank;
	bank.run();
	return 0;
}