#include <iostream>
#include <string>
using namespace std;

int modInverse(int a) {
    for (int i = 1; i < 26; i++)
        if ((a * i) % 26 == 1) return i;
    return -1;
}

int main() {
    string text;
    int k[2][2];

    cout << "Enter plaintext: ";
    getline(cin, text);

    cout << "Enter 2x2 key matrix: ";
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            cin >> k[i][j];

    // remove spaces & uppercase
    string t = "";
    for (char c : text) {
        if (c != ' ') t += toupper(c);
    }
    if (t.size() % 2 != 0) t += 'X';

    string cipher = "", plain = "";

    // Encryption
    for (int i = 0; i < t.size(); i += 2) {
        int a = t[i] - 'A', b = t[i + 1] - 'A';
        cipher += char((k[0][0] * a + k[0][1] * b) % 26 + 'A');
        cipher += char((k[1][0] * a + k[1][1] * b) % 26 + 'A');
    }

    // Inverse matrix
    int det = (k[0][0] * k[1][1] - k[0][1] * k[1][0]) % 26;
    if (det < 0) det += 26;
    int invDet = modInverse(det);
    if (invDet == -1) {
        cout << "Key matrix is not invertible modulo 26." << endl;
        return 0;
    }

    int inv[2][2];
    inv[0][0] = (k[1][1] * invDet) % 26;
    inv[1][1] = (k[0][0] * invDet) % 26;
    inv[0][1] = ((-k[0][1] * invDet) % 26 + 26) % 26;
    inv[1][0] = ((-k[1][0] * invDet) % 26 + 26) % 26;

    // Decryption
    for (int i = 0; i < cipher.size(); i += 2) {
        int a = cipher[i] - 'A', b = cipher[i + 1] - 'A';
        plain += char((inv[0][0] * a + inv[0][1] * b) % 26 + 'A');
        plain += char((inv[1][0] * a + inv[1][1] * b) % 26 + 'A');
    }

    cout << "Encrypted Output: " << cipher << endl;
    cout << "Decrypted Output: " << plain << endl;

    return 0;
}
