#include <iostream>
using namespace std;

// Simple round function: XOR with key and add key
int roundFunction(int R, int key) {
    return (R ^ key) + key;
}

int main() {
    int plaintext, numRounds;
    cout << "Enter plaintext (integer): ";
    cin >> plaintext;
    cout << "Enter number of rounds: ";
    cin >> numRounds;

    int keys[10];
    for (int i = 0; i < numRounds; i++) {
        cout << "Enter key for round " << i + 1 << ": ";
        cin >> keys[i];
    }

    // Split plaintext into two halves (16-bit plaintext → 8-bit halves)
    int L = (plaintext >> 8) & 0xFF;
    int R = plaintext & 0xFF;

    cout << "\nEncryption Rounds:" << endl;
    for (int i = 0; i < numRounds; i++) {
        int newL = R;
        int newR = L ^ roundFunction(R, keys[i]);
        L = newL;
        R = newR;
        cout << "Round " << i + 1 << ": L = " << L << ", R = " << R << endl;
    }

    int ciphertext = (L << 8) | (R & 0xFF);
    cout << "Encrypted Output: " << ciphertext << endl;

    cout << "\nDecryption Rounds:" << endl;
    for (int i = numRounds - 1; i >= 0; i--) {
        int newR = L;
        int newL = R ^ roundFunction(L, keys[i]);
        R = newR;
        L = newL;
        cout << "Round " << (numRounds - i) << ": L = " << L << ", R = " << R << endl;
    }

    int decrypted = (L << 8) | (R & 0xFF);
    cout << "Decrypted Output: " << decrypted << endl;

    return 0;
}
