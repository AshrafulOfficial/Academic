#include<bits/stdc++.h>
using namespace std;

map<char, vector<string>> productions;
map<char, set<char>> firstSet;
set<char> visited;

void findFirst(char symbol) {

    // If already computed, return
    if (visited.count(symbol))
        return;

    visited.insert(symbol);

    for (string prod : productions[symbol]) {

        // If production is epsilon
        if (prod == "#") {   // # represents epsilon
            firstSet[symbol].insert('#');
            continue;
        }

        for (int i = 0; i < prod.length(); i++) {
            char ch = prod[i];

            // If terminal
            if (!isupper(ch)) {
                firstSet[symbol].insert(ch);
                break;
            }
            // If non-terminal
            else {
                findFirst(ch);

                // Add FIRST(ch) except epsilon
                for (char f : firstSet[ch]) {
                    if (f != '#')
                        firstSet[symbol].insert(f);
                }

                // If epsilon is not in FIRST(ch), stop
                if (firstSet[ch].count('#') == 0)
                    break;

                // If epsilon and last symbol
                if (i == prod.length() - 1)
                    firstSet[symbol].insert('#');
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter number of productions: ";
    cin >> n;

    cout << "Use # for epsilon\n";

    for (int i = 0; i < n; i++) {
        string prod;
        cin >> prod;

        char lhs = prod[0];
        string rhs = prod.substr(3);  // A->aB

        productions[lhs].push_back(rhs);
    }

    // Compute FIRST for all non-terminals
    for (auto p : productions) {
        char nonTerminal = p.first;
        findFirst(nonTerminal);
    }

    // Print FIRST sets
    cout << "\nFIRST Sets:\n";
    for (auto p : firstSet) {
        cout << "FIRST(" << p.first << ") = { ";
        for (char f : p.second) {
            cout << f << " ";
        }
        cout << "}\n";
    }

    return 0;
}
