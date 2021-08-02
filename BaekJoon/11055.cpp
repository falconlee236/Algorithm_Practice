/*11055*/
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int arr[1000] = {};
    int dp[1000] = {};
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    dp[0] = arr[0];
    int res = dp[0];
    for(int i = 1; i < n; i++){
        int cur_dp = 0;
        for(int j = i - 1; j >= 0; j--) if(arr[i] > arr[j]) cur_dp = max(cur_dp, dp[j]);
        dp[i] = arr[i] + cur_dp;
        res = max(res, dp[i]);
    }
    cout << res;
    return 0;
}
