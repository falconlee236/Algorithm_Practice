#include <iostream>
#include <algorithm>
using namespace std;

int	dp[1000010];

int main(void){
	int n, k; cin >> n >> k;
	for(int i = n + 1; i <= k; i++){
		if (i & 1 || i / 2 < n) dp[i] = dp[i - 1] + 1;
		else dp[i] = min(dp[i - 1], dp[i / 2]) + 1;
	}
	cout << dp[k];
}