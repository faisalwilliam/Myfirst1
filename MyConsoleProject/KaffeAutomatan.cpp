// Kaffeautomaten.cpp
// Deklarationen for tv�  classar privat oc public som beskriver det som p�g�r i automaten
// Efter att anv�ndaren stopppat in pengar
//Konstruktorn ska tilldela de som standard privata datamed

#include <iostream>
using namespace std;

class Kaffeautomaten {  // Class definition for a coffee vending machine
private:                // Private properties of the vending machine



    string productName;   // Namn p� den valda produkten
    double price;         // Pris p� valda produkten
    double money;         //Pengar infogade av anv�ndaren
    double payment;       //M�ngden pengar som belalas
    double change;        //Ber�knad f�r�nderin som ska returneras
    char   product;       //produktkod (tecken) vald av anv�daren


public:
    Kaffeautomaten(char product, double money) {  // Konstrukt�r f�r automaten med produktval
        //och pengar som parametrar
        this->money = money;                       // Tilldela mottagna pengar till pengaegendomen
        // Byt skiftl�ge f�r att fastst�lla produktdetaljerna
        //  baserat p� inmatningstecknet
        switch (product) {
        case 'K':
            productName = "kaffe";
            price = 12.00;
            break;
        case 'E':
            productName = "Espresso";
            price = 14.00;
            break;
        case 'C':
            productName = "Choklad";
            price = 11.50;
            break;
        case 'L':
            productName = "Kaffe Latte";
            price = 13.00;
            break;
        case 'P':
            productName = "Cappuccino";
            price = 13.50;
            break;
        default:                    // Om en ogiltig produkt v�ljs
            cout << "\n\tDu valde ett ogiltigt produkt" << endl;

            price = 0;              // S�tt priset till 0 f�r ogiltig produkt
            productName = "";       // Rensa produktnamnet
            break;
        }
        payment = money;              // St�ll in betalningen lika med de angivna pengarna
        change = payment - price;     // Ber�kna f�r�nringen

    }


    void change_in_coins() {
        //Denna funktion, change_in_coins, anv�nds f�r att hantera �ndringsprocessen i en varuautomat.
        //Den kontrollerar f�rst om en produkt har valts, och om inte, uppmanas anv�ndareatt v�lja en giltig produkt.
       //Sedan kontrolleras om betalningen r�cker f�r den valda produkten, och om inte, uppmanas anv�ndare att v�lja en giltig betalning och produkt.
       //Den uppmanar sedan anv�ndaren att v�lja en giltig produkt genom att visa alternativ och ta in f�r den nya produkten.
       //Det uppmanar ocks� att anv�nda att mata in summa pengar och initieras en ny instans av klassen Kaffeautomaten med anv�ndarens nya val.
       // Om betalningen �r tillr�cklig exekveras resten av metoden
        if (productName == "") {
            cout << "\t\x8Fterg\x86 till huvudmenyn och v\x84lj ett giltigt produkt." << endl;
            return;
        }
        if (payment < price) {
            cout << "\t\x8Fterg\x86 till huvudmenyn och v\x84lj ett giltigt betalning." << endl;
            // Prompt the user to choose a valid product
            cout << "\t V\x84lja ett produkt:" << endl;
            cout << "\n";
            cout << "\t K: (kaffe)        12.00 kr" << endl;
            cout << "\t E: (Espresso)     14.00 kr" << endl;
            cout << "\t C: (Choklad)      11.50 kr" << endl;
            cout << "\t L: (Kaffe Latte)  13.00 kr" << endl;
            cout << "\t P: (Cappuccino)   13.50 kr" << endl;
            cout << "\n\t";
            char newProduct;
            cin >> newProduct;
            cout << "\tAnge dina pengar :" << endl;
            cout << "\t";
            double newMoney;
            cin >> newMoney;
            // Initialize a new instance of the Kaffeautomaten class with the user's new choices
            Kaffeautomaten newK(newProduct, newMoney);
            newK.change_in_coins();
            cout << "\n";
        }
        // ... rest of the method ...

            // Ber�kna f�r�ndringsf�rdelningen i mynt
        int total = static_cast<double>(change * 100);    // Konvertera v�xel till �re
        int ten = total / 1000;
        int five = (total % 1000) / 500;
        int one = ((total % 1000) % 500) / 100;
        int half = (((total % 1000) % 500) % 100) / 50;
        int rest = (((total % 1000) % 500) % 100) % 50;    // Amount less than 50 �re
        // Visa k�p och �ndra detaljer
        cout << "\tDer " << productName << " koster: " << price << " kroner" << endl;
        cout << "\tdu betalar: " << money << " kroner" << endl;
        cout << "\tdu f\x86r: " << change << " kroner tillbaka" << endl;
        cout << "\ttack f\x86r att du best\x84llde en " << productName << endl;
        cout << "\tv\x84nligen ta din " << productName << " och din v\x84xel" << endl;
        // Visa antalet mynt i v�xlingen
        cout << "\tNumber of 10 kr coins: " << ten << endl;
        cout << "\tNumber of 5 kr coins: " << five << endl;
        cout << "\tNumber of 1 kr coins: " << one << endl;
        cout << "\tNumber of 50 \x94re coins: " << half << endl;
        // Hantera �rendet n�r det finns en rest som inte �r noll mindre �n 50 �re
        if (rest > 0) {
            cout << "Oj, du f\x86r " << rest << " \x94re tillbaka som vi inte kan v\x84xla.\
        Du f\x86r en extra kram ist\x84llet!" << endl;
        }
    }
};
// Huvudfunktion d�r programmet startar exekvering
int main() {

    cout << "\n";
    // V�lkomstmeddelande och menyuppmaning

    cout << "\t V\x84lkommen till kaffe shoppen: " << endl;
    cout << "\t V\x84lja ett produkt:" << endl;
    cout << "\n";

    // Visa produktalternativ och deras priser
    cout << "\t K: (kaffe)        12.00 kr" << endl;
    cout << "\t E: (Espresso)     14.00 kr" << endl;
    cout << "\t C: (Choklad)      11.50 kr" << endl;
    cout << "\t L: (Kaffe Latte)  13.00 kr" << endl;
    cout << "\t P: (Cappuccino)   13.50 kr" << endl;


    cout << "\n\t";

    // Variabel f�r att h�lla produkten som valts av anv�ndaren
    char product;
    cin >> product;  // Anv�ndarinput f�r produktvalet
    // Be anv�ndaren att ange summan pengar de har
    cout << "\tAnge dina pengar :" << endl;
    cout << "\t";
    double money;
    cin >> money; // Anv�ndarinmatning f�r pengar

    // Skapa en instans av klassen Kaffeautomaten och initiera den med anv�ndarens val
    Kaffeautomaten k(product, money);

    k.change_in_coins();  // Anropa metoden f�r att ber�kna och visa f�r�ndringen

    cout << "\n";
    return  0; // Sluta p� progrmmet
}