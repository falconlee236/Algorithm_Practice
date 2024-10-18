#include <iostream>
using namespace std;
int dp[1001][1001];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, t, total = 0; cin >> n >> t;
	int time[n + 1], cost[n + 1]; for(int i = 1; i <= n; i++) cin >> time[i] >> cost[i], total += cost[i];
	for(int i = 1; i <= n; i++) for(int j = 1; j <= 1000; j++) dp[i][j] = (j >= time[i] ? max(dp[i - 1][j - time[i]] + cost[i], dp[i - 1][j]) : dp[i - 1][j]);
	cout << total - dp[n][t];
}