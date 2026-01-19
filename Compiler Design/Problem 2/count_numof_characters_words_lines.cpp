#include<bits/stdc++.h>
using namespace std;
int main(){
    string line;
    int lineCount = 0, characterCount = 0, wordCount = 0;

    ifstream file("input.txt");
    while(getline(file, line)){
        lineCount++;
        characterCount = characterCount + line.length();

        bool inword = false;
        for(int i=0; i<line.length(); i++){
            if(isspace(line[i])){
                inword = false;
            }
            else if(inword == false){
                wordCount++;
                inword = true;
            }
        }
    }

    file.close();

    cout<<"Number of line: "<<lineCount<<endl;
    cout<<"Number of character: "<<characterCount<<endl;
    cout<<"Number of word: "<<wordCount<<endl;

    return 0;

}
