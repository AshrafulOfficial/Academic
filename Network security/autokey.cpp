#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string text, key;
    cout << "Enter plaintext: ";
    getline(cin, text);
    cout << "Enter key (word): ";
    getline(cin, key);

    // Build extended key using only letters from plaintext
    string fullKey = key;
    for (int i = 0; fullKey.size() < text.size(); i++) {
        if (isalpha(text[i])) {
            fullKey += toupper(text[i]);
        }
    }

    string cipher = "";
    int ki = 0;
    // Encryption
    for (char c : text) {
        if (!isalpha(c)) {
            cipher += c; // preserve spaces/punctuation
        } else {
            char base = isupper(c) ? 'A' : 'a';
            char k = toupper(fullKey[ki]);
            cipher += ((c - base) + (k - 'A')) % 26 + base;
            ki++;
        }
    }

    string plain = "";
    string tempKey = key;
    int ti = 0;
    // Decryption
    for (char c : cipher) {
        if (!isalpha(c)) {
            plain += c;
        } else {
            char base = isupper(c) ? 'A' : 'a';
            char k = toupper(tempKey[ti]);
            char p = ((c - base) - (k - 'A') + 26) % 26 + base;
            plain += p;
            tempKey += toupper(p); // extend key with decrypted letter
            ti++;
        }
    }

    cout << "Encrypted Output: " << cipher << endl;
    cout << "Decrypted Output: " << plain << endl;

    return 0;
}
