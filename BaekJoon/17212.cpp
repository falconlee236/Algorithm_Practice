#include <iostream>
int dp[100010];
using namespace std;
int main(void){
	int n; cin >> n;
	for(int i = 1; i <= n; i++){
		dp[i] = dp[i - 1] + 1;
		if (i - 2 >= 0) dp[i] = min(dp[i], dp[i - 2] + 1);
		if (i - 5 >= 0) dp[i] = min(dp[i], dp[i - 5] + 1);
		if (i - 7 >= 0) dp[i] = min(dp[i], dp[i - 7] + 1);
	}
	cout << dp[n];
}