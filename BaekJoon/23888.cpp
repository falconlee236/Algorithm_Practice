#include <iostream>
using namespace std;
using ll = long long;
ll gcd(ll a, ll b){
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	ll a, d, q; cin >> a >> d >> q;
	while (q--){
		ll num, l, r; cin >> num >> l >> r;
		if (num == 1) cout << ((2 * a + (r - 1) * d) * r - (2 * a + (l - 2) * d) * (l - 1)) / 2 << "\n";
		else cout << (l == r ? a + (l - 1) * d : gcd(a, d)) << "\n";
	}
}