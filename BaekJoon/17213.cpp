#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    int n, m; cin >> n >> m;
    int dp[41][31] = {0, };
    for(int i = 1; i <= 40; i++){
        for(int j = 0; j <= 30; j++){
            dp[i][j] = (j == 0 || i == j ? 1 : dp[i - 1][j] + dp[i - 1][j - 1]);
        }
    }
    cout << dp[m - 1][n - 1];
}