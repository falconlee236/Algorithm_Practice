/*2579*/
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int arr[301] = {};
    int dp[301] = {};
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    dp[3] = max(arr[1] + arr[3], arr[2] + arr[3]);
    if(n == 1 || n == 2 || n == 3){
        cout << dp[n];
        return 0;
    }
    for(int i = 4; i <= n; i++) dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]);
    cout << dp[n];
    return 0;
}
