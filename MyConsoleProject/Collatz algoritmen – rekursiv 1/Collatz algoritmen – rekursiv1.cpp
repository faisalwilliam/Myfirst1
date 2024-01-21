// Collatz algoritmen – rekursiv.cpp
// Rekursiv funktion och anropar den från main().
// Läserin pos. heltaltar det gångar 3 och addera 1,
// Om det är udda. Delar det med 2 om talet är jämnt,
// Upprepa samma sak med resultatet till den blir 1,
// Använder is-sats där repetitionen -->

#include <iostream>
using namespace std;

// Rekursiv funktion för att implementera Collatz-algoritmen
	void collatz(int no)
	{
	cout<< "\n\t" << no;// Skriver ut det aktuella talet
	// Basfall: om nej är 1 slutar kedjan
	if (no == 1) {
		return; // Avslutar rekursionen när ni når talet 1
		// Recursive case for odd numbers
	}
	else if (no % 2 == 1) {
		collatz(3 * no + 1); // Rekursivt anrop med 3n+1 om talet är udda
		// Recursive caes for even numbers
	}
	else {
    collatz(no / 2); // Rekursivt anrop med n/2 om talet är jämnt

	}
    }
	int main()
	{
		int no;
		cout<<"\n\tMata in ett pos.heltal:\t"; // Ber användaren mata in ett positivt heltal
		cin >> no; // Tar emot användarens inmatning
		collatz(no);// Anropar den rekursiva Collatz-funktionen
		cout<<"\n\n\t";//skriv ny rad i slutet av programmet
		 
		return 0;
		
	}
	/*Fördelar:

    Enkelhet: Ofta en rak lösning som är lätt att förstå, särskilt,
    om problemet är naturligt rekursivt,
    Ren kod : Kan leda till kortare och mer läsbar kod jämfört med dess iterativa motsvarighet.

     Nackdelar :

	 Stack Användning : Varje rekursivt anrop lägger till ett lager på call stacken.
	 Om det finns för många anrop, kan programmet sluta med ett stack overflow.
	 Prestanda : Ibland kan rekursiva funktioner vara långsammare på grund av overhead
	 Från flera funktionsanrop.

    */