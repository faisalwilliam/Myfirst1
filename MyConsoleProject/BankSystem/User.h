// Klass User representerar en bankanv�ndare med ett anv�ndare namn, en PIN-Kod och flera konto
/*class User {
public:
	string username;
	int pin;
	vector<Account> accounts;
	// Konstruk�rn initierar anv�ndare med anv�ndarenamn, en PIN _Kod och deras konto
	User(string username, int pin, vector<Account> accounts)
		: username(username), pin(pin), accounts(accounts){}



};
*/
#include <string>
#include <vector>
#include "Account.h" // Assuming Account is a class defined in another file
class User {
public:
	string username;
	int pin;
	vector<Account> accounts;
	// Constructor initializes User with a username, a PIN code, and their accounts
	User(string username, int pin, vector<Account> accounts)
		: username(username), pin(pin), accounts(accounts) {}
};