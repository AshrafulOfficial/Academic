#include<bits/stdc++.h>
using namespace std;

string input;
int pos = 0;
bool e = false;

void E();
void E_prime();
void T();
void T_prime();
void F();

void error() 
{
    e = true;
}

void match(char expected) 
{
    if(e) return;
    
    if(pos < input.size() && input[pos] == expected) {
        pos++;
    } else {
        error();
    }
}

void F() 
{
    if(e) return;
    
    if(pos < input.size() && input[pos] == '(') {
        match('(');
        E();
        match(')');
    } else if(pos < input.size() && input[pos] == 'i') {
        match('i');
        match('d');
    } else {
        error();
    }
}

void T_prime() 
{
    if(e) return;
    
    if(pos < input.size() && input[pos] == '*') {
        match('*');
        F();
        T_prime();
    }
}

void T() 
{
    if(e) return;
    
    F();
    T_prime();
}

void E_prime() 
{
    if(e) return;
    
    if(pos < input.size() && input[pos] == '+') {
        match('+');
        T();
        E_prime();
    }
}

void E() 
{
    if(e) return;
    
    T();
    E_prime();
}

int main()
{
    while(true) {
        pos = 0;
        e = false;
        
        cout << "Enter input string: ";
        cin >> input;
        
        E();
        
        if(!e && pos == input.size()) {
            cout << "String is accepted!" << endl;
        } else {
            cout << "String is rejected!" << endl;
        }
    }
}