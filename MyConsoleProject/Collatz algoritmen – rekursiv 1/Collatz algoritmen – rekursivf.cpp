// Collatz algoritmen � rekursiv.cpp
// Rekursiv funktion och anropar den fr�n main().
// L�serin pos. heltaltar det g�ngar 3 och addera 1,
// Om det �r udda. Delar det med 2 om talet �r j�mnt,
// Upprepa samma sak med resultatet till den blir 1,
// Anv�nder is-sats d�r repetitionen -->

#include <iostream>
using namespace std;

// Rekursiv funktion f�r att implementera Collatz-algoritmen
	void collatz(int no)
	{
	cout<< "\n\t" << no;// Skriver ut det aktuella talet
	// Basfall: om nej �r 1 slutar kedjan
	if (no == 1) {
		return; // Avslutar rekursionen n�r ni n�r talet 1
		// Recursive case for odd numbers
	}
	else if (no % 2 == 1) {
		collatz(3 * no + 1); // Rekursivt anrop med 3n+1 om talet �r udda
		// Recursive caes for even numbers
	}
	else {
    collatz(no / 2); // Rekursivt anrop med n/2 om talet �r j�mnt

	}
    }
	int main()
	{
		int no;
		cout<<"\n\tMata in ett pos.heltal:\t"; // Ber anv�ndaren mata in ett positivt heltal
		cin >> no; // Tar emot anv�ndarens inmatning
		collatz(no);// Anropar den rekursiva Collatz-funktionen
		cout<<"\n\n\t";//skriv ny rad i slutet av programmet
		 
		return 0;
		
	}
	/*F�rdelar:

    Enkelhet: Ofta en rak l�sning som �r l�tt att f�rst�, s�rskilt,
    om problemet �r naturligt rekursivt,
    Ren kod : Kan leda till kortare och mer l�sbar kod j�mf�rt med dess iterativa motsvarighet.

     Nackdelar :

	 Stack Anv�ndning : Varje rekursivt anrop l�gger till ett lager p� call stacken.
	 Om det finns f�r m�nga anrop, kan programmet sluta med ett stack overflow.
	 Prestanda : Ibland kan rekursiva funktioner vara l�ngsammare p� grund av overhead
	 Fr�n flera funktionsanrop.

    */