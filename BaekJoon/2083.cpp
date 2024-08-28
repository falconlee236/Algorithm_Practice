#include <iostream>
using namespace std;
int main(){
    while(1){
        string s;
        int a, b; cin >> s >> a >> b;
        if (s == "#" && a == 0 && b == 0) break;
        cout << s << " " << (a > 17 || b >= 80 ? "Senior" : "Junior") << "\n";
    }
}