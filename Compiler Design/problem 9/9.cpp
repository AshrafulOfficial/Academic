#include<bits/stdc++.h>
using namespace std;
int main(){
    string input;
    cout<<"Enter the string(operator must be one character): ";
    cin>>input;

    int state = 0;
    for(int i=0; i<input.length(); i++){
        switch(state){
            case 0:
                if(isalpha(input[i])){
                    state = 1;
                }
                else if(input[i] == '_'){
                    state = 1;
                }
                else if(input[i] == '+' || input[i] ==  '-' || input[i] ==  '*' || input[i] ==  '/' || input[i] ==  '%' || input[i] ==  '='
                                    || input[i] ==  '<' || input[i] ==  '>'|| input[i] ==  '!'){
                    state = 2;
                }
                else if(isdigit(input[i])){
                    state = 3;
                }
                else{
                    state = -1;
                }
            break;

            case 1:
                if(isalnum(input[i])){
                    state = 1;
                }
                else if(input[i] == '_'){
                    state = 1;
                }
                else{
                    state = -1;
                }
            break;

            case 3:
                if(isdigit(input[i])){
                    state = 3;
                }
                else{
                    state = -1;
                }
            break;
        }

        if(state == -1){
            break;
        }
    }

    if(state == 1){
        cout<<"The identifier is valid recognize by DFA."<<endl;
    }
    else if(state == 2){
        cout<<"The operator is valid recognize by DFA."<<endl;
    }
    else if(state == 3){
        cout<<"The constant is valid recognize by DFA."<<endl;
    }
    else if(state == -1){
        cout<<"The identifier/opertor/contant is invalid."<<endl;
    }

    return 0;
}
