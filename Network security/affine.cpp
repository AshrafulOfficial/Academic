#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int modInverse(int a) {
    for (int i = 1; i < 26; i++) {
        if ((a * i) % 26 == 1) return i;
    }
    return -1; // no inverse exists
}

int main() {
    string text, cipher = "", plain = "";
    int a, b;

    cout << "Enter plaintext: ";
    getline(cin, text);
    cout << "Enter key a (must be coprime with 26): ";
    cin >> a;
    cout << "Enter key b: ";
    cin >> b;

    int inv = modInverse(a);
    if (inv == -1) {
        cout << "Invalid key 'a'! It has no modular inverse modulo 26." << endl;
        return 0;
    }

    // Encryption
    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            cipher += ((a * (c - base) + b) % 26) + base;
        } else {
            cipher += c; // preserve spaces/punctuation
        }
    }

    // Decryption
    for (char c : cipher) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            plain += (inv * ((c - base - b + 26) % 26)) % 26 + base;
        } else {
            plain += c;
        }
    }

    cout << "Encrypted Output: " << cipher << endl;
    cout << "Decrypted Output: " << plain << endl;

    return 0;
}
