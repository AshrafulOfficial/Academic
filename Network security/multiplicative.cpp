#include <iostream>
#include <string>
using namespace std;

// function to find modular inverse
int modInverse(int k) {
    for (int i = 1; i < 26; i++) {
        if ((k * i) % 26 == 1) return i;
    }
    return -1; // no inverse exists
}

int main() {
    string text, cipher = "", plain = "";
    int key;

    cout << "Enter plaintext (letters only): ";
    getline(cin, text);
    cout << "Enter key: ";
    cin >> key;

    int inv = modInverse(key);
    if (inv == -1) {
        cout << "Invalid key! No modular inverse exists for this key under mod 26." << endl;
        return 0;
    }

    // Encryption
    for (char c : text) {
        if (c == ' ') {
            cipher += ' ';
        } else if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            cipher += ((c - base) * key) % 26 + base;
        } else {
            cipher += c; // preserve non-alphabetic characters
        }
    }

    // Decryption
    for (char c : cipher) {
        if (c == ' ') {
            plain += ' ';
        } else if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            plain += ((c - base) * inv) % 26 + base;
        } else {
            plain += c;
        }
    }

    cout << "Encrypted Output: " << cipher << endl;
    cout << "Decrypted Output: " << plain << endl;

    return 0;
}
