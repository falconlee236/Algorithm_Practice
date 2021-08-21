/*1759*/
/*Cheating*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int l, c;
char alpha[16];

void func(int pos, string str, int vowel, int cons){
    if(str.size() == l){
        if(vowel < 1 || cons < 2) return;
        cout << str << "\n";
        return;
    }
    
    for(int i = pos; i < c; i++){
        char ch = alpha[i];
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            func(i + 1, str + ch, vowel + 1, cons);
        else 
            func(i + 1, str + ch, vowel, cons + 1);
    }
}

int main(){
    cin >> l >> c;
    for(int i = 0; i < c; i++) cin >> alpha[i];
    sort(alpha, alpha + c);
    func(0, "", 0, 0);
    return 0;
}