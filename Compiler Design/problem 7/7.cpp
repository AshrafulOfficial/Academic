#include<bits/stdc++.h>
using namespace std;
int main(){
    string code;
    cout<<"Enter the string(code line): ";
    getline(cin, code);

    int count = 0;
    for(int i=0; i<code.length(); i++){
        if(code[i] == '='){
            if(code[i+1] == '='){
                count++;
                i++;
            }
            else if(code[i+1] != '='){
                count++;
            }
        }

        else if(code[i] == '+'){
            if(code[i+1] == '+'){
                count++;
                i++;
            }
            else if(code[i+1] = '='){
                count++;
                i++;
            }
            else if(code[i+1] != '+' && code[i+1] != '='){
                count++;
            }
        }

        else if(code[i] == '-'){
            if(code[i+1] == '-'){
                count++;
                i++;
            }
            else if(code[i+1] = '='){
                count++;
                i++;
            }
            else if(code[i+1] != '-' && code[i+1] != '='){
                count++;
            }
        }

        else if(code[i] == '*'){
            if(code[i+1] == '='){
                count++;
                i++;
            }
            else if(code[i+1] != '='){
                count++;
            }
        }
        else if(code[i] == '/'){
            if(code[i+1] == '='){
                count++;
                i++;
            }
            else if(code[i+1] != '='){
                count++;
            }
        }

        else if(code[i] == '%'){
            if(code[i+1] == '='){
                count++;
                i++;
            }
            else if(code[i+1] != '='){
                count++;
            }
        }

        else if(code[i] == '>'){
            if(code[i+1] == '='){
                count++;
                i++;
            }
            else if(code[i+1] != '='){
                count++;
            }
        }
        
        else if(code[i] == '<'){
            if(code[i+1] == '='){
                count++;
                i++;
            }
            else if(code[i+1] != '='){
                count++;
            }
        }

        else if(code[i] == '!'){
            if(code[i+1] == '='){
                count++;
                i++;
            }
            else if(code[i+1] != '='){
                count++;
            }
        }

        else if(code[i] == '&'){
            if(code[i+1] == '&'){
                count++;
                i++;
            }
        }

        else if(code[i] == '|'){
            if(code[i+1] == '|'){
                count++;
                i++;
            }
        }
    }

    cout<<"Number of operator is: "<<count<<endl;

    return 0;
}