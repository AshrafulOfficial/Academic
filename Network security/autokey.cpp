#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string text, cipher = "", plain = "";
    int key;

    cout << "Enter plaintext: ";
    getline(cin, text);

    cout << "Enter numeric key (0-25): ";
    cin >> key;

    int prevKey = key;

    // Encryption
    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';

            int p = c - base;
            int ciph = (p + prevKey) % 26;

            cipher += ciph + base;

            // Next key = current plaintext value
            prevKey = p;
        } else {
            cipher += c;
        }
    }

    prevKey = key;

    // Decryption
    for (char c : cipher) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';

            int ciph = c - base;
            int p = (ciph - prevKey + 26) % 26;

            plain += p + base;

            // Next key = decrypted plaintext value
            prevKey = p;
        } else {
            plain += c;
        }
    }

    cout << "Encrypted Output: " << cipher << endl;
    cout << "Decrypted Output: " << plain << endl;

    return 0;
}