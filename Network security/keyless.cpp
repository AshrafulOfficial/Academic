#include <iostream>
#include <vector>
#include <string>
using namespace std;

string encrypt(string text, int rail) {
    vector<string> r(rail);
    int row = 0, dir = 1;

    for (char c : text) {
        r[row] += c;
        if (row == 0) dir = 1;
        else if (row == rail - 1) dir = -1;
        row += dir;
    }

    string cipher = "";
    for (string s : r) cipher += s;
    return cipher;
}

string decrypt(string cipher, int rail) {
    vector<vector<char>> mat(rail, vector<char>(cipher.size(), '\n'));
    int row = 0, dir = 1;

    // mark zig-zag positions
    for (int i = 0; i < cipher.size(); i++) {
        mat[row][i] = '*';
        if (row == 0) dir = 1;
        else if (row == rail - 1) dir = -1;
        row += dir;
    }

    // fill marked positions with ciphertext
    int k = 0;
    for (int i = 0; i < rail; i++)
        for (int j = 0; j < cipher.size(); j++)
            if (mat[i][j] == '*' && k < cipher.size())
                mat[i][j] = cipher[k++];

    // read plaintext in zig-zag
    string plain = "";
    row = 0, dir = 1;
    for (int i = 0; i < cipher.size(); i++) {
        plain += mat[row][i];
        if (row == 0) dir = 1;
        else if (row == rail - 1) dir = -1;
        row += dir;
    }

    return plain;
}

int main() {
    string text;
    int rail;

    cout << "Enter plaintext: ";
    getline(cin, text);
    cout << "Enter number of rails: ";
    cin >> rail;

    string cipher = encrypt(text, rail);
    string plain = decrypt(cipher, rail);

    cout << "Encrypted Output: " << cipher << endl;
    cout << "Decrypted Output: " << plain << endl;

    return 0;
}
