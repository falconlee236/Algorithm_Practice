/*2225*/
#include <iostream>
#define DIV 1000000000
using namespace std;

int main(){
    int n,k; cin >> n >> k;
    long long dp[201][201] = {};
    for(int i = 0; i <= n; i++) dp[i][1] = 1;
    
    for(int i = 2; i <= k; i++){
        for(int j = 0; j <= n; j++){
            for(int o = 0; o <= j; o++){
                dp[j][i] += dp[o][i - 1];
            }
            dp[j][i] %= DIV;
        }
    }
    cout << dp[n][k];
    return 0;
}