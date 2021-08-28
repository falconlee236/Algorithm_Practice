/*17404*/
/*Cheating*/
#include <iostream>
#include <algorithm>
using namespace std;

int arr[1002][3], dp[1002][3];

int main() {
	int n; cin >> n;
	for(int i = 1; i <= n; i++) scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
	int inf = 987654321;
	int res[3] = {};
	for(int i = 0; i < 3; i++){
	    for(int j = 0; j < 3; j++){
	        if(i == j) dp[1][j] = arr[1][j];
	        else dp[1][j] = inf;
	    }
	    
	    for(int i = 2; i <= n; i++){
	        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
	        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
	        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
	    }
	    
	    int ans = 987654321;
	    for(int j = 0; j < 3; j++){
	        if(i == j) continue;
	        ans = min(ans, dp[n][j]);
	    }
	    res[i] = ans;
	}
	cout << min({res[0], res[1], res[2]});
	return 0;
}
