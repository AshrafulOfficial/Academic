#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of productions: ";
    cin >> n;

    map<char, vector<string>> productions;
    char startSymbol;
    string prod;

    cout << "Enter productions in form A->XYZ\n";

    for (int i = 0; i < n; i++) {
        cin >> prod;
        char lhs = prod[0];
        string rhs = prod.substr(3);

        productions[lhs].push_back(rhs);

        if (i == 0)
            startSymbol = lhs; // first production is start symbol
    }

    // Start derivation
    string str(1, startSymbol);
    cout << "\nLeftmost Derivation steps:\n";
    cout << str << endl;

    while (true) {
        bool replaced = false;

        // scan for leftmost non-terminal
        for (int i = 0; i < str.size(); i++) {
            char ch = str[i];

            if (isupper(ch)) { // non-terminal
                // use the first production for simplicity
                str = str.substr(0, i) + productions[ch][0] + str.substr(i + 1);
                cout << str << endl;
                replaced = true;
                break; // only replace leftmost
            }
        }

        if (!replaced)
            break; // all terminals, stop derivation
    }

    return 0;
}
