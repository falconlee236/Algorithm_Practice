#include <iostream>
using namespace std;
using ll = long long;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, flag = 1; cin >> n;
	ll arr[n], ans = 0; for(ll &x : arr) cin >> x;
	while (flag){
		flag = 0;
		for(int i = 1; i < n - 1; i++){
			if (arr[i - 1] + arr[i + 1] >= 2 * arr[i]) continue;
			ll tmp = max(0LL, arr[i] - (arr[i - 1] + arr[i + 1]) / 2);
			ans += tmp; arr[i] -= tmp; flag = 1;
		}
	}
	cout << ans;
}