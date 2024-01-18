#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[25][1005];

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int c, n; cin >> c >> n;
    vector<int> cost(n + 1), person(n + 1);
    for(int i = 0; i < 25; i++){
        for(int j = 0; j < 1005; j++) dp[i][j] = 2000000000;
    }
    for(int i = 1; i <= n; i++) cin >> cost[i] >> person[i];
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= c; j++){
            for(int k = 1; i - k >= 0; k++){
                cout << person[i] * k << " " << j << "\n";
                if(j - person[i] * k < 0) dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = min(dp[i - k][j], dp[i - 1][j - person[i] * k] + cost[i] * k);
            }
        }
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= c; j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << dp[n][c] << "\n";
}