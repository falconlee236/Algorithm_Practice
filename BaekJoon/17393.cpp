#include <iostream>
#include <algorithm>
using ll = long long;
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    ll a[n], b[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cout << upper_bound(b + i + 1, b + n, a[i]) - b - (i + 1) << " ";
}
