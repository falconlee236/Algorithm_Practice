/*11723*/
/*Got it!*/
/*09:45*/
#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int m; cin >> m;
    int bit = 0;
    while(m--){
        string str; cin >> str;
        if(str == "all"){
            bit = (1 << 21) - 1;
            continue;
        }
        if(str == "empty"){
            bit = 0;
            continue;
        }
        int num; cin >> num;
        if(str == "add") bit |= (1 << num);
        if(str == "remove") bit &= ~(1 << num);
        if(str == "check") cout << (bit & (1 << num) ? 1 : 0) << "\n";
        if(str == "toggle") bit ^= (1 << num);
    }
    return 0;
}