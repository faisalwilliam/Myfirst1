#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
bool palindrom(char* a) {
    int start = 0;
    int end = strlen(a) - 1;
    while (start < end) {
        if (a[start] != a[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}
void removeSpaces(char* str) {
    char* out = str, * put = str;
    for (; *str != '\0'; ++str) {
        if (*str != ' ')
            *put++ = *str;
    }
    *put = '\0';
}
int main() {
    const int SIZE = 256;
    char str[SIZE];
    cout << "Enter strings (or an empty line to suggest palindromes): " << endl;
    while (true) {
        cin.getline(str, SIZE);

        if (strlen(str) == 0) {
            cout << "No palindrome found. Here are some suggestions: radar, level, racecar, madam, refer." << std::endl;
            break;
        }

        removeSpaces(str);
        if (palindrom(str)) {
           cout << "You've found a palindrome!" <<endl;
            break;
        }
        else {
           cout << "Not a palindrome. Try again: " <<endl;
        }
    }
    return 0;
}