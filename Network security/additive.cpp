#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string text, cipher = "", plain = "";
    int key;

    cout << "Enter plaintext (letters only): ";
    getline(cin, text);
    cout << "Enter key (shift value): ";
    cin >> key;

    // Normalize key to range [0,25]
    key = key % 26;

    // Encryption
    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            cipher += (c - base + key) % 26 + base;
        } else {
            cipher += c; // preserve spaces and punctuation
        }
    }

    // Decryption
    for (char c : cipher) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            plain += (c - base - key + 26) % 26 + base;
        } else {
            plain += c;
        }
    }

    cout << "Encrypted Output: " << cipher << endl;
    cout << "Decrypted Output: " << plain << endl;

    return 0;
}
