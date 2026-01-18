#include<bits/stdc++.h>
using namespace std;
int main(){
    string input;
    cout<<"Enter an identifier: ";
    cin>>input;

    int state = 0;
    bool valid = true;
    for(int i=0; i<input.length(); i++){
        switch(state) {
            case 0:
                if(isalpha(input[i])){
                    state = 1;
                }
                else if(input[i] == '_'){
                    state = 1;
                }
                else{
                    valid = false;
                }
                break; //without break it will check next cases
            case 1:
                if(isalnum(input[i])){
                    state = 1;
                }
                else if(input[i] == '_'){
                    state = 1;
                }
                else{
                    valid = false;
                }
                break;
        }
        if(valid == false){
            break;
        }
    }

    if(valid == true && state == 1){
        cout<<"The valid identifier is recognize by NFA."<<endl;
    }
    else{
        cout<<"The invalid identifier is not recognize by NFA."<<endl;
    }

    return 0;
}