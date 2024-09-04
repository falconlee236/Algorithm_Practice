#include <iostream>
using namespace std;
int dp[400010];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	int arr[n]; for(int &x: arr) cin >> x;
	for(int i = n - 1; i >= 0; i--) dp[i] = (!arr[i] ? dp[i + 1] : dp[i + arr[i] + 1]) + 1;
	for(int i = 0; i < n; i++) cout << dp[i] << " ";
}