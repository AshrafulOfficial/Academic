#include<bits/stdc++.h>
using namespace std;
int main(){
    ifstream file("input.txt");

    int lineCount=0, characterCount=0, wordCount=0;
    string line;

    while(getline(file, line)){
        lineCount++;

        characterCount = characterCount + line.length();

        bool inWord = false;
        for(char ch : line){
            if(isspace(ch)){    //isspace checks space,tabs,newline, carrige return
                inWord = false;
            }
            else if(!inWord){
                wordCount++;
                inWord = true;
            }
        }
    }

    file.close();

    cout<<"The number of characters: "<<characterCount<<endl;
    cout<<"The number of line: "<<lineCount<<endl;
    cout<<"The number of word: "<<wordCount<<endl;

    return 0;
}