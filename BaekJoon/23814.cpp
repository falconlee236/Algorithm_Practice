#include <iostream>

using namespace std;
using ll = long long;

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t; cin >> t;
    ll n, m, k; cin >> n >> m >> k;
    ll a = n % t;
    ll b = m % t;
    ll key[4], ans[4];
    ll res = 0;
    ans[0] = n / t + m / t + k / t;
    key[0] = k;
    ans[1] = (n + (t - a)) / t + m / t + (k - (t - a)) / t;
    key[1] = (k - (t - a));
    ans[2] = n / t + (m + (t - b)) / t + (k - (t - b)) / t;
    key[2] = (k - (t - b));
    ans[3] = (n + (t - a)) / t + (m + (t - b)) / t + (k - (t - a) - (t - b)) / t;
    key[3] = (k - (t - a) - (t - b));
    for(int i = 0; i < 4; i++){
        if (ans[i] == (n + m + k) / t and res < key[i]) res = key[i];
    }
    cout << res << "\n";
    return 0;
}