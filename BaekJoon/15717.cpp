#include <iostream>
#define DIV 1000000007
using namespace std;
using ll = long long;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	ll n, ans = 1, base = 2; cin >> n;
	if (!n) {
		cout << 1;
		return 0;
	}
	n--;
	while (n){
		if (n & 1LL) ans = (ans * base) % DIV;
		base = (base * base) % DIV;
		n >>= 1LL;
	}
	cout << ans;
}