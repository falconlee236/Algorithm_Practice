#include <iostream>

using namespace std;

int dp[1001];

int main(void){
	int n; cin >> n;
	dp[1] = 1;
	dp[3] = 1;
	dp[4] = 1;
	for(int i = 5; i <= n; i++)
	{
		dp[i] = 0;
		if (!dp[i - 1] || !dp[i - 3] || !dp[i - 4]) dp[i] = 1;
	}
	cout << (dp[n] ? "SK" : "CY") << "\n";
	return 0;
}