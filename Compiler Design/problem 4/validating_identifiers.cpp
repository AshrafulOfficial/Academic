#include<bits/stdc++.h>
using namespace std;
int main() {
    string identifier;
    string keywords[] = {"int", "float", "double", "void", "using", 
        "if", "else", "char", "for", "while", "do", "else", "case", 
        "switch", "break", "main", "return", "continue", "struct", 
        "class", "long", "true", "flase", "bool", "namespace", "private",
        "public", "new", "default", "signed", "unsigned", "detect"};

    cin>>identifier;

    bool test = false;
    if(identifier[0] == '_' || isalpha(identifier[0])){
        for(int i=1; i<identifier.size(); i++){
            if(identifier[i] == '_' || isalpha(identifier[i]) || isdigit(identifier[i])){
                test = true;
            }
            else{
                test = false;
                break;
            }
        }
    }

    if(test == true){
        for(int i=0; i<sizeof(keywords)/sizeof(keywords[0]); i++){
            if(identifier == keywords[i]){
                test = false;
                break;
            }
            else{
                test = true;
            }
        }
    }

    if(test == true){
        cout<<"This is a valid identifier."<<endl;
    }
    else{
        cout<<"This is a invalid identifier."<<endl;
    }

    return 0;

}
    