#include <iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    long long a, b, c; cin >> a >> b >> c;
    cout << (a + b >= 2LL * c ? (a + b - (2LL * c)) : (a + b));
}