#include <iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int v, e; cin >> v >> e; cout << 2 - v + e << "\n";
    }
}