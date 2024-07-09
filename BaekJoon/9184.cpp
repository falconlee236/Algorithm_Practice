#include <iostream>
using namespace std;
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int dp[21][21][21] = {0, };
    for(int i = 0; i < 21; i++){
        for(int j = 0; j < 21; j++){
            for(int k = 0; k < 21; k++){
                if (i == 0 || j == 0 || k == 0) dp[i][j][k] = 1;
                else if (i < j && j < k) dp[i][j][k] = dp[i][j][k - 1] + dp[i][j - 1][k - 1] - dp[i][j - 1][k];
                else dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] - dp[i - 1][j - 1][k - 1];
            }
        }
    }
    while (1){
        int a, b, c; cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << (a <= 0 || b <= 0 || c <= 0 ? 1 : (a > 20 || b > 20 || c > 20 ? dp[20][20][20] : dp[a][b][c])) << "\n";
    }
}