#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

string cleanText(string s) {
    string r = "";
    for (char c : s) {
        if (c != ' ') r += c; // keep original case, just remove spaces
    }
    return r;
}

vector<pair<char, int>> getOrder(string key) {
    vector<pair<char, int>> order;
    for (int i = 0; i < key.size(); i++) {
        order.push_back({tolower(key[i]), i}); // sort by lowercase for consistency
    }
    stable_sort(order.begin(), order.end());
    return order;
}

int main() {
    string text, key;
    cout << "Enter plaintext: ";
    getline(cin, text);
    cout << "Enter keyword: ";
    getline(cin, key);

    text = cleanText(text);
    int col = key.size();
    int row = (text.size() + col - 1) / col;

    while (text.size() < row * col) text += 'x'; // pad with lowercase x

    vector<vector<char>> mat(row, vector<char>(col));
    int k = 0;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            mat[i][j] = text[k++];

    vector<pair<char, int>> order = getOrder(key);

    // Encryption
    string cipher = "";
    for (auto p : order) {
        int c = p.second;
        for (int i = 0; i < row; i++)
            cipher += mat[i][c];
    }

    // Decryption
    vector<vector<char>> dmat(row, vector<char>(col));
    k = 0;
    for (auto p : order) {
        int c = p.second;
        for (int i = 0; i < row; i++)
            dmat[i][c] = cipher[k++];
    }

    string plain = "";
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            plain += dmat[i][j];

    // strip padding
    while (!plain.empty() && plain.back() == 'x') plain.pop_back();

    cout << "Encrypted Output: " << cipher << endl;
    cout << "Decrypted Output: " << plain << endl;

    return 0;
}
