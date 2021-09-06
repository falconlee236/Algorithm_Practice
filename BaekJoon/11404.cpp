/*11404*/
/*Cheating*/
#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int dp[105][105];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	fill(dp[0], dp[0] + 105 * 105, INF);
	for(int i = 0; i < m; i++){
	    int a, b, c; cin >> a >> b >> c;
	    dp[a][b] = min(c, dp[a][b]);
	}
	
	for(int i = 1; i <= n; i++) dp[i][i] = 0;
	
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << (dp[i][j] == INF ? 0 : dp[i][j]) << " ";
        }
        cout << "\n";
    }
	return 0;
}
