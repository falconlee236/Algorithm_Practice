#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    ll arr[n]; for(auto &x : arr) cin >> x;
    sort(arr, arr + n);
    while (m--){
        int type; cin >> type;
        if (type == 3){
            ll i, j; cin >> i >> j;
            int end = upper_bound(arr, arr + n, j) - arr, start = lower_bound(arr, arr + n, i) - arr;
            cout << end - start << "\n";
            continue;
        }
        ll k; cin >> k;
        if (type == 1) cout << n - (lower_bound(arr, arr + n, k) - arr) << "\n";
        else cout << n - (upper_bound(arr, arr + n, k) - arr) << "\n";
    }
}