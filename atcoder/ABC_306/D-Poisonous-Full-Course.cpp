#include <iostream>
#include <algorithm>

using namespace std;
long long dp[2][300010];

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        int ispoision; long long taste; cin >> ispoision >> taste;
        if (ispoision){
            dp[0][i] = dp[0][i - 1];
            dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] + taste);
        }
        else{
            dp[1][i] = dp[1][i - 1];
            dp[0][i] = max(max(dp[0][i - 1], dp[0][i - 1] + taste), dp[1][i - 1] + taste);
        }
    }
    cout << max(dp[0][n] , dp[1][n]);
    return 0;
}