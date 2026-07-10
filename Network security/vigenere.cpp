#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string text, key, fullKey = "", cipher = "", plain = "";

    cout << "Enter plaintext: ";
    getline(cin, text);
    cout << "Enter keyword: ";
    getline(cin, key);

    // generate full key (skip spaces/punctuation)
    int j = 0;
    for (int i = 0; i < text.size(); i++) {
        if (isalpha(text[i])) {
            fullKey += key[j % key.size()];
            j++;
        } else {
            fullKey += text[i]; // preserve spaces/punctuation
        }
    }

    // Encryption
    for (int i = 0; i < text.size(); i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            char kbase = isupper(fullKey[i]) ? 'A' : 'a';
            cipher += ( (text[i] - base) + (toupper(fullKey[i]) - 'A') ) % 26 + base;
        } else {
            cipher += text[i];
        }
    }

    // Decryption
    for (int i = 0; i < cipher.size(); i++) {
        if (isalpha(cipher[i])) {
            char base = isupper(cipher[i]) ? 'A' : 'a';
            char kbase = isupper(fullKey[i]) ? 'A' : 'a';
            plain += ( (cipher[i] - base) - (toupper(fullKey[i]) - 'A') + 26 ) % 26 + base;
        } else {
            plain += cipher[i];
        }
    }

    cout << "Encrypted Output: " << cipher << endl;
    cout << "Decrypted Output: " << plain << endl;

    return 0;
}
