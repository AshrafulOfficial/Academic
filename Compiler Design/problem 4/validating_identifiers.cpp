#include<bits/stdc++.h>
using namespace std;
int main(){
    string id;

    cout<<"Enter a identifier: ";
    cin>>id;

    string key[] = {"int", "float", "double", "long", "if", "else", "break", "continue", 
                    "return", "using", "namespace", "void", "public", "private", "delete",
                    "for", "while", "char", "string", "struct", "new", "bool", "true",
                    "false", "signed", "unsigned","default", "swicth", "case", "class"};

    bool valid = false;
    if(id[0] == '_' || isalpha(id[0])){
        for(int i=1; i<id.length(); i++){
            if(id[i] == '_' || isalnum(id[i])){
                valid = true;
            }
            else{
                valid = false;
                break;
            }
        }
    }

    if(valid == true){
        for(int i=0; i<sizeof(key)/sizeof(key[0]); i++){
            if(id == key[i]){
                valid = false;
                break;
            }
            else{
                valid = true;
            }
        }
    }

    if(valid == true){
        cout<<"The identifier is valid."<<endl;
    }
    else{
        cout<<"The identifier is invalid."<<endl;
    }

    return 0;
}
