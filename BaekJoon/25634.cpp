#include <iostream>
#include <algorithm>
using namespace std;
int dp[200001];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	int a[n], ans = 0, state;
	for(int &x : a) cin >> x;
	for(int i = 1; i <= n; i++){
		cin >> state;
		if (state){
			ans += a[i - 1];
			dp[i] = max(dp[i - 1] - a[i - 1], -a[i - 1]);
		} else dp[i] = max(dp[i - 1] + a[i - 1], a[i - 1]);
	}
	cout << ans + *max_element(dp + 1, dp + n + 1);
}