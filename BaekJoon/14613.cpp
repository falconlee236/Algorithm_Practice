/*14613*/
/*Cheating*/
#include <iostream>
using namespace std;

double dp[21][3501];

int main(){
    double w, l, d;
    cin >> w >> l >> d;
    dp[0][2000] = 1;
    for(int i = 1; i < 21; i++){
        for(int j = 1000; j <= 3500; j++){
            dp[i][j] += dp[i - 1][j + 50] * l;
            dp[i][j] += dp[i - 1][j - 50] * w;
            dp[i][j] += dp[i - 1][j] * d;
        }
    }
    
    cout << fixed;
    cout.precision(8);
    double ans[5] = {};
    for(int i = 1000; i < 1500; i++) ans[0] += dp[20][i];
    for(int i = 1500; i < 2000; i++) ans[1] += dp[20][i];
    for(int i = 2000; i < 2500; i++) ans[2] += dp[20][i];
    for(int i = 2500; i < 3000; i++) ans[3] += dp[20][i];
    for(int i = 3000; i < 3500; i++) ans[4] += dp[20][i];
    
    for(auto x : ans) cout << x << "\n";
    return 0;
}