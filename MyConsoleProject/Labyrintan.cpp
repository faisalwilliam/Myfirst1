

// Labyrinten.cpp
// declared och initiolized av två variabler h,b
//ritad mellan 12 Dubbla (LGT) tecknet och deras koder

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main() {
	srand(time(0)); // Initiera slumpmässiga
	int randNo = 0;
	char code = 0;
	int h = 20, b = 50; // Default höjd and bredd värde
	cout << "\n\tAnge Labyrintens bredd:(50)";
	cin >> b; // Input labyrinten berdd
	cout << "\n\tAnge Labyrintens höjd:(20)";
	cin >> h; // Input labyrinten höjd
	cout << "\n";
	cout << "\t" << endl;
	for (int i = 1; i <= h; i++) { // Loop genom varje row
		cout << "\n\t";
		for (int j = 1; j <= b; j++) { // Loop genom varje  kolumn
			randNo = rand() % 12; // loop ett slumptal mellan 0 och 11
			if (randNo == 1) {
				code = 185;
				cout << char(code); // Print character with code 185
			}
			else if (randNo == 2) {
				code = 186;
				cout << char(code); // Print character with code 186
			}
			else if (randNo == 3) {
				code = 187;
				cout << char(code); // Print character with code 187
			}
			else if (randNo == 4) {
				code = 188;
				cout << char(code); // Print character with code 188
			}
			else if (randNo == 5) {
				code = 206;
				cout << char(code); // Print character with code 206
			}
			else if (randNo == 6) {
				code = 205;
				cout << char(code); // Print character with code 205
			}
			else if (randNo == 7) {
				code = 204;
				cout << char(code); // Print character with code 204
			}
			else if (randNo == 8) {
				code = 203;
				cout << char(code); // Print character with code 203
			}
			else if (randNo == 9) {
				code = 202;
				cout << char(code); // Print character with code 202
			}
			else if (randNo == 10) {
				code = 201;
				cout << char(code); // Print character with code 201
			}
			else if (randNo == 11) {
				code = 206;
				cout << char(code); // Print character with code 206
			}
			else {
				cout << ' '; // Print nothing if randNo is not 1-11
			}
		}
	}
}