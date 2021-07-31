/*2193*/
#include <iostream>

using namespace std;

int main(){
    int n; cin >> n;
    long long dp[91] = {0, 1, 1};
    for(int i = 2; i <= n; i++) dp[i] = dp[i - 2] + dp[i - 1];
    cout << dp[n];
    return 0;
}