#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;

    if(s == "a"){
        cout<<"The pattern matched: a"<<endl;
    }
    else if(s == "abb"){
        cout<<"The pattern matched: abb"<<endl;
    }
    else{
        int i=0, count_b = 0;

        while(i<s.length() && s[i] == 'a'){
            i++;
        }

        while(i<s.length() && s[i] == 'b'){
            count_b ++;
            i++;
        }

        if(i == s.length() && count_b >= 1){
            cout<<"The pattern is matched: a*b+"<<endl;
        }
        else{
            cout<<"The pattern is not matched."<<endl;
        }
    }
    return 0;
}