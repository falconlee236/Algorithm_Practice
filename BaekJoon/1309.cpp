#include <iostream>
using namespace std;
int dp[100001];
int main(){
	int n; cin >> n, dp[0] = 1, dp[1] = 3;
	for(int i = 2; i <= n; i++) dp[i] = (2 * dp[i - 1] + dp[i - 2]) % 9901; cout << dp[n];
}