#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;
using ll = long long;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, b; cin >> n >> b;
    ll sum_x = 0, sum_y = 0;
    while (n--){
        ll x, y; cin >> x >> y;
        sum_y += (b - y);
        sum_x += x;
    }
    sum_y *= -1;
    if (sum_x == 0) cout << "EZPZ";
    else if (sum_y % sum_x == 0) cout << sum_y / sum_x;
    else {
        ll tmp_y = sum_y / __gcd(sum_x, sum_y), tmp_x = sum_x / __gcd(sum_x, sum_y);
        if (tmp_y > 0 && tmp_x > 0) cout << tmp_y << "/" << tmp_x;
        else if (tmp_y < 0 && tmp_x < 0) cout << -tmp_y << "/" << -tmp_x;
        else if (tmp_y < 0) cout << "-" << -tmp_y << "/" << tmp_x;
        else cout << "-" << tmp_y << "/" << -tmp_x;
    }
}