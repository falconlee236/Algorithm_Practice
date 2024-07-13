#include <iostream>
#define DIV 1000000009
using namespace std;
using ll = long long;
ll dp[1010][1010];
int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    dp[1][1] = 1; dp[2][1] = 1; dp[2][2] = 1;
    dp[3][1] = 1; dp[3][2] = 2; dp[3][3] = 1;
    for(int i = 4; i <= 1000; i++){
        for(int j = 2; j <= i; j++) dp[i][j] = (dp[i - 1][j - 1] % DIV + dp[i - 2][j - 1] % DIV + dp[i - 3][j - 1]) % DIV;
    } 
    while (T--){
        int n, m; cin >> n >> m;
        ll ans = 0;
        for(int i = m; i > 0; i--) ans = (ans + dp[n][i]) % DIV;
        cout << ans << "\n";
    }
}