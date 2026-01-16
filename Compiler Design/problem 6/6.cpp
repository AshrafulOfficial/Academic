#include<bits/stdc++.h>
using namespace std;
int main(){
    string op;
    cout<<"Enter a operator: ";
    cin>>op;

    string operators[] = {"+", "-", "*", "/", "%", "==", "!=", ">=",
        "<=", ">", "<", "&&", "||", "!", "=", "+=", "-=", "*=", "/=",
        "%=", "++", "--"};
    
    bool test = false;
    for(int i=0; i<sizeof(operators)/sizeof(operators[0]); i++){
        if(op == operators[i]){
            test = true;
            break;
        }
        else{
            test = false;
        }
    }

    if(test == true){
        cout<<"Valid operator"<<endl;
    }
    else{
        cout<<"Invalid Operator"<<endl;
    }
    return 0;
}