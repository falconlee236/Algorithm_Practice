#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0);
    while (1){
        string s;
        getline(cin, s);
        if (s == "#") return 0;
        int ans = 0;
        for(auto x : s){
            x = tolower(x);
            if (x == 'a' || x == 'i' || x == 'e' || x == 'o' || x == 'u') ans++;
        }
        cout << ans << "\n";
    }
}