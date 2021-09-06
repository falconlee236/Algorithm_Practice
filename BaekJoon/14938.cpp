/*14938*/
/*Got it!*/
#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int dp[105][105];
int items[105];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, r; cin >> n >> m >> r;
    fill(dp[0], dp[0] + 105 * 105, INF);
    for(int i = 1; i <= n; i++){
        cin >> items[i];
        dp[i][i] = 0;
    }
    
    for(int i = 0; i < r; i++){
        int a, b, c; cin >> a >> b >> c;
        dp[a][b] = c;
        dp[b][a] = c;
    }
    
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    
    int ans = -1;
    for(int i = 1; i <= n; i++){
        int res = 0;
        for(int j = 1; j <= n; j++){
            if(dp[i][j] <= m) res += items[j];
        }
        ans = max(res, ans);
    }
    cout << ans;
    return 0;
}