#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll cur; int n, ans = 1; cin >> n >> cur;
    ll arr[n - 1]; for(ll &x : arr) cin >> x;
    sort(arr, arr + n - 1);
    for(ll x : arr){
        if (cur > x) cur += x;
        else ans = 0;
    }
    cout << (ans ? "Yes" : "No");
}