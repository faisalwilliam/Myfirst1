//1. Palindrom – en lek med ord
#include <iostream>
#include <string>
using namespace std;


int main() {
    string str;
    int i, length, length1;
    int flag = 0;
    //inmatning
    cout << "Enter a string: ";
    getline(cin, str, '\n');

    length = str.length();//strängens längd
    //hitta och ta bort mellanslag i en sträng
    for (int i = 0; i < length; i++) {
        if (str[i] == ' ') {
            str.erase(i, 1);
            i--;
        }
    }

    length1 = str.length();//lång nyrad
    //definition av polidrom
    for (i = 0; i < length1; i++) {
        if (str[i] != str[length1 - i - 1]) {
            flag = 1;
            break;
        }
    }
    //utgångsresultat
    if (flag) {
        cout << str << " is not a palindrome" << endl;
    }
    else {
        cout << str << " is a palindrome" << endl;
    }
    system("pause");
    return 0;
}