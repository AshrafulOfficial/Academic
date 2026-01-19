#include<bits/stdc++.h>
using namespace std;
int main(){
    string line;
    cout<<"Enter a line: ";

    getline(cin, line);

    if(line[0] == '/' && line[1] == '/'){
        cout<<"This is a single line comment."<<endl;
    }
    else if((line[0] == '/' && line[1] == '*') && (line[line.length()-2]) == '*' && (line[line.length()-1] == '/')){
        cout<<"This is a multiline comment."<<endl;
    }
    else{
        cout<<"This is not a comment."<<endl;
    }

    return 0;
}
