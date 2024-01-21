// Kaffeautomaten.cpp
// Deklarationen for två  classar privat oc public som beskriver det som pågår i automaten
// Efter att användaren stopppat in pengar
//Konstruktorn ska tilldela de som standard privata datamed

#include <iostream>
using namespace std;

class Kaffeautomaten {  // Class definition for a coffee vending machine
private:                // Private properties of the vending machine



    string productName;   // Namn på den valda produkten
    double price;         // Pris på valda produkten
    double money;         //Pengar infogade av användaren
    double payment;       //Mängden pengar som belalas
    double change;        //Beräknad föränderin som ska returneras
    char   product;       //produktkod (tecken) vald av anvädaren


public:
    Kaffeautomaten(char product, double money) {  // Konstruktör för automaten med produktval
        //och pengar som parametrar
        this->money = money;                       // Tilldela mottagna pengar till pengaegendomen
        // Byt skiftläge för att fastställa produktdetaljerna
        //  baserat på inmatningstecknet
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
        default:                    // Om en ogiltig produkt väljs
            cout << "\n\tDu valde ett ogiltigt produkt" << endl;

            price = 0;              // Sätt priset till 0 för ogiltig produkt
            productName = "";       // Rensa produktnamnet
            break;
        }
        payment = money;              // Ställ in betalningen lika med de angivna pengarna
        change = payment - price;     // Beräkna föränringen

    }


    void change_in_coins() {
        //Denna funktion, change_in_coins, används för att hantera ändringsprocessen i en varuautomat.
        //Den kontrollerar först om en produkt har valts, och om inte, uppmanas användareatt välja en giltig produkt.
       //Sedan kontrolleras om betalningen räcker för den valda produkten, och om inte, uppmanas användare att välja en giltig betalning och produkt.
       //Den uppmanar sedan användaren att välja en giltig produkt genom att visa alternativ och ta in för den nya produkten.
       //Det uppmanar också att använda att mata in summa pengar och initieras en ny instans av klassen Kaffeautomaten med användarens nya val.
       // Om betalningen är tillräcklig exekveras resten av metoden
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

            // Beräkna förändringsfördelningen i mynt
        int total = static_cast<double>(change * 100);    // Konvertera växel till öre
        int ten = total / 1000;
        int five = (total % 1000) / 500;
        int one = ((total % 1000) % 500) / 100;
        int half = (((total % 1000) % 500) % 100) / 50;
        int rest = (((total % 1000) % 500) % 100) % 50;    // Amount less than 50 öre
        // Visa köp och ändra detaljer
        cout << "\tDer " << productName << " koster: " << price << " kroner" << endl;
        cout << "\tdu betalar: " << money << " kroner" << endl;
        cout << "\tdu f\x86r: " << change << " kroner tillbaka" << endl;
        cout << "\ttack f\x86r att du best\x84llde en " << productName << endl;
        cout << "\tv\x84nligen ta din " << productName << " och din v\x84xel" << endl;
        // Visa antalet mynt i växlingen
        cout << "\tNumber of 10 kr coins: " << ten << endl;
        cout << "\tNumber of 5 kr coins: " << five << endl;
        cout << "\tNumber of 1 kr coins: " << one << endl;
        cout << "\tNumber of 50 \x94re coins: " << half << endl;
        // Hantera ärendet när det finns en rest som inte är noll mindre än 50 öre
        if (rest > 0) {
            cout << "Oj, du f\x86r " << rest << " \x94re tillbaka som vi inte kan v\x84xla.\
        Du f\x86r en extra kram ist\x84llet!" << endl;
        }
    }
};
// Huvudfunktion där programmet startar exekvering
int main() {

    cout << "\n";
    // Välkomstmeddelande och menyuppmaning

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

    // Variabel för att hålla produkten som valts av användaren
    char product;
    cin >> product;  // Användarinput för produktvalet
    // Be användaren att ange summan pengar de har
    cout << "\tAnge dina pengar :" << endl;
    cout << "\t";
    double money;
    cin >> money; // Användarinmatning för pengar

    // Skapa en instans av klassen Kaffeautomaten och initiera den med användarens val
    Kaffeautomaten k(product, money);

    k.change_in_coins();  // Anropa metoden för att beräkna och visa förändringen

    cout << "\n";
    return  0; // Sluta på progrmmet
}