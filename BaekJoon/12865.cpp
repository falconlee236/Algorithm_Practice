/*12865*/
/*Cheating*/
#include <iostream>
#include <algorithm>
using namespace std;

int dp[101][100001], arr[101][2];

int main() {
    int n, k; cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> arr[i][0] >> arr[i][1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            if(arr[i][0] <= j) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - arr[i][0]] + arr[i][1]);
            else dp[i][j] = dp[i - 1][j];
        }
    }
    printf("%d", dp[n][k]);
	return 0;
}
