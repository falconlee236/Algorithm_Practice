#include <iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    string a, b, c; cin >> a >> b;
    for(char x : a){
        if ('0' > x || x > '9') c += x;
    }
    cout << (c.find(b) != -1);
}