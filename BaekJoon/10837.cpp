#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int k, c, m, n; cin >> k >> c;
    while (c--){
        cin >> m >> n;
        if (m == n) cout << "1\n";
        else if (m > n) cout << (abs(m - n) - (k - max(m, n)) <= 2 ? "1\n" : "0\n");
        else cout << (abs(m - n) - (k - max(m, n)) <= 1 ? "1\n" : "0\n");
    }
}