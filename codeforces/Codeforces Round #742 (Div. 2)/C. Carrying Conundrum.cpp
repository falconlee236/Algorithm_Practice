/*00:17*/
#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        string str; cin >> str;
        string odd, even;
        for(int i = 0; i < str.size(); i++){
            if(i % 2) odd += str[i];
            else even += str[i];
        }
        if(!odd.size()) odd += "0";
        if(!even.size()) even += "0";
        cout << (stoi(odd) + 1) * (stoi(even) + 1) - 2 << "\n";
    }
}