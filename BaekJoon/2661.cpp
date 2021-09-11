/*2661*/
/*Cheating*/
#include <iostream>
#include <string>
using namespace std;

int n;
string num[3] = {"1", "2", "3"};

void good(int cnt, string sub){
    for(int i = 1; i <= (cnt / 2); i++){
        string a = sub.substr(cnt - i, i);
        string b = sub.substr(cnt - i * 2, i);
        if(a == b) return;
    }
 
    if(cnt == n){
        cout << sub << "\n";
        exit(0);
    }
    for(int i = 0; i < 3; i++){
        good(cnt + 1, sub + num[i]);
    }
}

int main(){
    cin >> n;
    good(0, "");
    return 0;
}