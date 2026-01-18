#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of productions: ";
    cin >> n;

    map<char, vector<string>> productions;
    string prod;
    cout << "Enter productions in form A->XYZ\n";

    for (int i = 0; i < n; i++) {
        cin >> prod;
        char lhs = prod[0];
        string rhs = prod.substr(3);
        productions[lhs].push_back(rhs);
    }

    cout << "\nLeft Factored Grammar:\n";

    for (auto p : productions) {
        char lhs = p.first;
        vector<string> rhsList = p.second;

        bool factored = false;

        // Check for common prefix among productions
        for (int i = 0; i < rhsList.size(); i++) {
            string prefix = rhsList[i];

            for (int j = i + 1; j < rhsList.size(); j++) {
                // find common prefix
                int k = 0;
                while (k < prefix.size() && k < rhsList[j].size() && prefix[k] == rhsList[j][k])
                    k++;

                if (k > 0) { // common prefix found
                    string commonPrefix = prefix.substr(0, k);

                    // create new non-terminal
                    string newNT = string(1, lhs) + "'";

                    cout << lhs << " -> " << commonPrefix << newNT << endl;

                    // suffixes for new non-terminal
                    string suf1 = rhsList[i].substr(k);
                    string suf2 = rhsList[j].substr(k);

                    cout << newNT << " -> ";
                    if (suf1.empty()) cout << "#"; else cout << suf1;
                    cout << " | ";
                    if (suf2.empty()) cout << "#"; else cout << suf2;
                    cout << endl;

                    factored = true;
                    break;
                }
            }
            if (factored) break;
        }

        if (!factored) {
            // no factoring needed
            for (string s : rhsList) {
                cout << lhs << " -> " << s << endl;
            }
        }
    }

    return 0;
}
