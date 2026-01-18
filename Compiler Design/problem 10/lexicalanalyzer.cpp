#include<bits/stdc++.h>
using namespace std;

// Check if keyword
bool isKeyword(string s) {
    string keywords[] = {"int", "float", "double", "char", "if", "else", "while", "for", "return"};
    for(string k : keywords) {
        if(s == k)
            return true;
    }
    return false;
}

// Check if operator
bool isOperator(char ch) {
    string ops = "+-*/=%<>!";
    return ops.find(ch) != string::npos;
}

// Check if separator
bool isSeparator(char ch) {
    string sep = ";,(){}[]";
    return sep.find(ch) != string::npos;
}

int main() {
    ifstream fin("input.txt");   // source program file
    if(!fin) {
        cout << "File not found!" << endl;
        return 0;
    }

    char ch;
    string token = "";

    while(fin.get(ch)) {

        // Ignore spaces, tabs, newlines
        if(ch == ' ' || ch == '\t' || ch == '\n')
            continue;

        // Handle single-line comment //
        if(ch == '/') {
            char next = fin.peek();
            if(next == '/') {
                while(fin.get(ch) && ch != '\n');
                continue;
            }
            // Handle multi-line comment /* */
            else if(next == '*') {
                fin.get(); // consume *
                while(fin.get(ch)) {
                    if(ch == '*' && fin.peek() == '/') {
                        fin.get();
                        break;
                    }
                }
                continue;
            }
        }

        // Identifier or keyword
        if(isalpha(ch) || ch == '_') {
            token = ch;
            while(fin.get(ch) && (isalnum(ch) || ch == '_')) {
                token += ch;
            }
            fin.unget();

            if(isKeyword(token))
                cout << token << " : Keyword" << endl;
            else
                cout << token << " : Identifier" << endl;
        }

        // Constant
        else if(isdigit(ch)) {
            token = ch;
            while(fin.get(ch) && isdigit(ch)) {
                token += ch;
            }
            fin.unget();

            cout << token << " : Constant" << endl;
        }

        // Operator
        else if(isOperator(ch)) {
            cout << ch << " : Operator" << endl;
        }

        // Separator
        else if(isSeparator(ch)) {
            cout << ch << " : Separator" << endl;
        }
    }

    fin.close();
    return 0;
}
