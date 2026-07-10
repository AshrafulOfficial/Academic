#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string railFenceEncrypt(string text, int r) {
    vector<string> rail(r);
    int row = 0, dir = 1;

    for (char c : text) {
        rail[row] += c; // include spaces and preserve case
        if (row == 0) dir = 1;
        else if (row == r - 1) dir = -1;
        row += dir;
    }

    string res = "";
    for (string s : rail) res += s;
    return res;
}

string railFenceDecrypt(string cipher, int r) {
    vector<vector<char>> mat(r, vector<char>(cipher.size(), '\n'));
    int row = 0, dir = 1;

    // mark zig-zag positions
    for (int i = 0; i < cipher.size(); i++) {
        mat[row][i] = '*';
        if (row == 0) dir = 1;
        else if (row == r - 1) dir = -1;
        row += dir;
    }

    // fill marked positions with ciphertext
    int k = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < cipher.size(); j++)
            if (mat[i][j] == '*')
                mat[i][j] = cipher[k++];

    // read plaintext in zig-zag
    string res = "";
    row = 0, dir = 1;
    for (int i = 0; i < cipher.size(); i++) {
        res += mat[row][i];
        if (row == 0) dir = 1;
        else if (row == r - 1) dir = -1;
        row += dir;
    }
    return res;
}

int main() {
    string text;
    int rail;

    cout << "Enter plaintext: ";
    getline(cin, text);
    cout << "Enter number of rails: ";
    cin >> rail;

    string step1 = railFenceEncrypt(text, rail);

    // second step (reverse)
    string cipher = step1;
    reverse(cipher.begin(), cipher.end());

    // decryption
    string step2 = cipher;
    reverse(step2.begin(), step2.end());
    string plain = railFenceDecrypt(step2, rail);

    cout << "Encrypted Output: " << cipher << endl;
    cout << "Decrypted Output: " << plain << endl;

    return 0;
}
