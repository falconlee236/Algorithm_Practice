#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001][3];
int dp[100001][2];

int main() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) 
        scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
    
    dp[0][0] = max(arr[0][0], arr[0][1]); dp[0][1] = max(arr[0][1], arr[0][2]);
    
    for(int i = 1; i < n; i++){
        int a = dp[i - 1][0] + arr[i][0];
        int b = max(dp[i - 1][0], dp[i - 1][1]) + arr[i][1];
        int c = dp[i - 1][1] + arr[i][2];
        dp[i][0] = max(a, b); dp[i][1] = max(b, c);
    }
    cout << max(dp[n - 1][0], dp[n - 1][1]) << " ";
    
    dp[0][0] = min(arr[0][0], arr[0][1]); dp[0][1] = min(arr[0][1], arr[0][2]);
    
    for(int i = 1; i < n; i++){
        int a = dp[i - 1][0] + arr[i][0];
        int b = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][1];
        int c = dp[i - 1][1] + arr[i][2];
        dp[i][0] = min(a, b); dp[i][1] = min(b, c);
    }
    cout << min(dp[n - 1][0], dp[n - 1][1]) << " ";
    
    
	return 0;
}
