#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
using ll = long long;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    ll ans = 0, num;
    vector<ll> v;
    for(int i = 0; i < n; i++){
        cin >> num; ans += num;
        v.push_back(ans);
    }
    sort(v.begin(), v.end(), greater<ll>());
    ans = 0;
    for(int i = 0; i < k; i++) ans += v[i];
    cout << ans;
}