/*7579*/
/*Cheating*/
#include <iostream>
#include <algorithm>
using namespace std;

int dp[101][10001];
int mem[101], cost[101];

int main(){
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> mem[i];
    for(int i = 1; i <= n; i++) cin >> cost[i];
    int ans = 10000000;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 10001; j++){
            if(cost[i] <= j){
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + mem[i]);
            }
            else dp[i][j] = dp[i - 1][j];
            
            if(dp[i][j] >= m) ans = min(ans, j);
        }
    }
    cout << ans;
    return 0;
}