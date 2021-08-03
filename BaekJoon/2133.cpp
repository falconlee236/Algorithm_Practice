/*2133*/
#include <iostream>

using namespace std;

int main(){
    int dp[31] = {};
    int n; cin >> n;
    dp[0] = 1, dp[2] = 3;
    for(int i = 4; i <= n; i+=2){
        int s = 0;
        for(int j = i - 4; j >= 0; j--) s += dp[j];
        dp[i] = dp[i - 2] * 3 + s * 2;
    }
    cout << dp[n];
    return 0;
}