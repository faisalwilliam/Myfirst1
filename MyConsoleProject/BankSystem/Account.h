
// Klass Account representerar ett bankkonto med ett namn och saldo 

class Account {
public:
	// offentliga medlems variabler
	string name;
	float balance;
	// Konstruktören initierar konto med ett nman saldo
	Account (string name, float balance) : name (name), balance(balance){}
	// Visa kontonamn och saldo med fast precision for currency
	void display() const {
		cout<< name<<" :"<< fixed << setprecision(2) << balance << "SEK\n";

	 }

 };
