#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while(T--){
		int n, m, ans = 0; cin >> n >> m;
		int a[n], b[m];
		for(int& x : a) cin >> x; sort(a, a + n);
		for(int& x : b) cin >> x; sort(b, b + m);
		for(int x : a) ans += lower_bound(b, b + m, x) - b;
		cout << ans << "\n";
	}
}