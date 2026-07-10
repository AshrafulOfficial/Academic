#include <iostream>
#include <string>
using namespace std;

char mat[5][5];

string cleanText(string s) {
    string r = "";
    for (char c : s) {
        if (c >= 'a' && c <= 'z') c -= 32; // to uppercase
        if (c >= 'A' && c <= 'Z') {
            if (c == 'J') c = 'I'; // merge J with I
            r += c;
        }
    }
    return r;
}

void buildMatrix(string key) {
    bool used[26] = {false};
    used['J' - 'A'] = true; // J excluded
    string temp = cleanText(key);

    string full = "";
    for (char c : temp) {
        if (!used[c - 'A']) {
            used[c - 'A'] = true;
            full += c;
        }
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        if (!used[c - 'A']) {
            used[c - 'A'] = true;
            full += c;
        }
    }

    int k = 0;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            mat[i][j] = full[k++];
}

string makePairs(string s) {
    s = cleanText(s);
    string r = "";
    for (int i = 0; i < s.size(); i++) {
        r += s[i];
        if (i + 1 < s.size() && s[i] == s[i + 1]) {
            r += 'X';
        }
    }
    if (r.size() % 2 != 0) r += 'X';
    return r;
}

void findPos(char c, int &row, int &col) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (mat[i][j] == c) {
                row = i;
                col = j;
                return;
            }
        }
    }
}

string process(string text, int dir) {
    string r = "";
    for (int i = 0; i < text.size(); i += 2) {
        int r1, c1, r2, c2;
        findPos(text[i], r1, c1);
        findPos(text[i + 1], r2, c2);

        if (r1 == r2) {
            r += mat[r1][(c1 + dir + 5) % 5];
            r += mat[r2][(c2 + dir + 5) % 5];
        } else if (c1 == c2) {
            r += mat[(r1 + dir + 5) % 5][c1];
            r += mat[(r2 + dir + 5) % 5][c2];
        } else {
            r += mat[r1][c2];
            r += mat[r2][c1];
        }
    }
    return r;
}

int main() {
    string text, key;
    cout << "Enter plaintext: ";
    getline(cin, text);
    cout << "Enter keyword: ";
    getline(cin, key);

    buildMatrix(key);
    string prepared = makePairs(text);
    string cipher = process(prepared, 1);
    string plain = process(cipher, -1);

    cout << "Encrypted Output: " << cipher << endl;
    cout << "Decrypted Output: " << plain << endl;

    return 0;
}
