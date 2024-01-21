 
/*Fördelar:

  Enkelhet: Ofta en rak lösning som är lätt att förstå, särskilt om problemet är naturligt rekursivt.
   Ren kod : Kan leda till kortare och mer läsbar kod jämfört med dess iterativa motsvarighet.
  
  Nackdelar :

	Stack Användning : Varje rekursivt anrop lägger till ett lager på call stacken.
	Om det finns för många anrop, kan programmet sluta med ett stack overflow.
	Prestanda : Ibland kan rekursiva funktioner vara långsammare på grund av overhead 
	*/
	
	



#include <iostream>
using namespace std;
 // Collatz - algoritmens rekursiva funktion
 int collatz(int n) {
	if (n == 1) return 1; // Basfall: när n är 1 stoppas rekursionen.
	if (n % 2 == 0) {
		// Om n är jämnt är nästa sekvensnummer n / 2.
		return 1 + collatz(n / 2);
	}
	else {
		// Om n är udda är nästa sekvensnummer 3n + 1.
		return 1 + collatz(3 * n + 1);
	}
}
 int main() {
	 int number;
	 cout << "Enter a positive integer: ";
	 cin >> number;
	 if (number > 0) { // Se till att indata är ett positivt heltal.
	 cout << "Number of steps to reach 1: " << collatz(number) <<endl;
	 }
	 else {
		 cout << "Please enter a positive integer." <<endl;
 
 }
	

	return 0;
}


