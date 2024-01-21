 
/*F�rdelar:

  Enkelhet: Ofta en rak l�sning som �r l�tt att f�rst�, s�rskilt om problemet �r naturligt rekursivt.
   Ren kod : Kan leda till kortare och mer l�sbar kod j�mf�rt med dess iterativa motsvarighet.
  
  Nackdelar :

	Stack Anv�ndning : Varje rekursivt anrop l�gger till ett lager p� call stacken.
	Om det finns f�r m�nga anrop, kan programmet sluta med ett stack overflow.
	Prestanda : Ibland kan rekursiva funktioner vara l�ngsammare p� grund av overhead 
	*/
	
	



#include <iostream>
using namespace std;
 // Collatz - algoritmens rekursiva funktion
 int collatz(int n) {
	if (n == 1) return 1; // Basfall: n�r n �r 1 stoppas rekursionen.
	if (n % 2 == 0) {
		// Om n �r j�mnt �r n�sta sekvensnummer n / 2.
		return 1 + collatz(n / 2);
	}
	else {
		// Om n �r udda �r n�sta sekvensnummer 3n + 1.
		return 1 + collatz(3 * n + 1);
	}
}
 int main() {
	 int number;
	 cout << "Enter a positive integer: ";
	 cin >> number;
	 if (number > 0) { // Se till att indata �r ett positivt heltal.
	 cout << "Number of steps to reach 1: " << collatz(number) <<endl;
	 }
	 else {
		 cout << "Please enter a positive integer." <<endl;
 
 }
	

	return 0;
}


