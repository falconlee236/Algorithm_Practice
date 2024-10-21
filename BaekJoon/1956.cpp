#include <iostream>
#include <algorithm>
#define INF 123456789
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int v, e, ans = INF; cin >> v >> e;
    int dp[v + 1][v + 1];
    fill(&dp[0][0], &dp[v][v + 1], INF);
    for(int i = 0; i < e; i++){
        int a, b, c; cin >> a >> b >> c;
        dp[a][b] = c;
    }
    for(int i = 1; i <= v; i++){
        for(int j = 1; j <= v; j++){
            for(int k = 1; k <= v; k++) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        }
    }
    for(int i = 1; i <= v; i++) ans = min(ans, dp[i][i]);
    cout << (ans == INF ? -1 : ans);
}