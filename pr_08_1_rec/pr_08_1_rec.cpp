#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

bool ContainsWhileLetters(const char* str, int i, bool foundW, bool foundH, bool foundI, bool foundL, bool foundE) {
    if (str[i] == '\0') {
        return foundW && foundH && foundI && foundL && foundE;
    }

    if (str[i] == 'w') foundW = true;
    if (str[i] == 'h') foundH = true;
    if (str[i] == 'i') foundI = true;
    if (str[i] == 'l') foundL = true;
    if (str[i] == 'e') foundE = true;

    return ContainsWhileLetters(str, i + 1, foundW, foundH, foundI, foundL, foundE);
}


char* ReplaceWhile(char* str, char* dest, int i) {
    if (str[i] == '\0') {
        *dest = '\0'; 
        return dest;
    }

    if (strncmp(&str[i], "while", 5) == 0) {
        *dest++ = '*';
        *dest++ = '*';
        return ReplaceWhile(str, dest, i + 5);
    }
    else {
        *dest++ = str[i];
        return ReplaceWhile(str, dest, i + 1); 
    }
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);


    bool allLettersPresent = ContainsWhileLetters(str, 0, false, false, false, false, false);
    if (allLettersPresent)
        cout << "All letters from 'while'." << endl;
    else
        cout << "Doesn't contain all letters from 'while'." << endl;

    char* dest = new char[strlen(str) * 2 + 1];
    ReplaceWhile(str, dest, 0); 
    cout << "Modified string: " << dest << endl;

    delete[] dest;
    return 0;
}
