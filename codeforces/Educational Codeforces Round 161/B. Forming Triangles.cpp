#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(void){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while (T--){
		int n; cin >> n;
		ll ans = 0, cnt = 0;
		vector<ll> arr(n + 1, 0);
		for(int i = 0; i < n; i++){
			ll num; cin >> num;
			arr[num]++;
		}
		ll cum_cnt = 0;
		for(int i = 0; i <= n; i++){
			if (arr[i] > 2) ans += arr[i] * (arr[i] - 1) * (arr[i] - 2) / 6;
			if (arr[i] > 1) ans += arr[i] * (arr[i] - 1) / 2 * cum_cnt;
			cum_cnt += arr[i];
		}
		cout << ans << "\n";
	}
}