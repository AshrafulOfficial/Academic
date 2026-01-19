#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cout<<"Enter a strings: ";
    cin>>s;

    if(s == "a"){
        cout<<"The pattern matched: a"<<endl;
    }
    else if(s == "abb"){
        cout<<"The pattern matched: abb"<<endl;
    }
    else{
        int i=0;
        while(s[i] == 'a' && i<s.length()){
            i++;
        }

        int count = 0;

        while(s[i] == 'b' && i<s.length()){
            i++;
            count++;
        }

        if(i == s.length() && count >= 1){
        cout<<"The pattern matched: a*b+"<<endl;
        }
        else{
            cout<<"Pattern Doesen't matched."<<endl;
        }
    }

    return 0;
}
