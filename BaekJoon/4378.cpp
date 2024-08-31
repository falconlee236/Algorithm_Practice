#include <iostream>
#include <string>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s, convert = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    while (getline(cin, s)){
        for (char c : s) cout << (c == ' ' ? c : convert[convert.find(c) - 1]);
        cout << "\n";
    }
}