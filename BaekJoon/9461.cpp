/*9461*/
#include <iostream>

using namespace std;

int main(){
    long long dp[101] = {0, 1, 1, 1, 2, 2, };
    for(int i = 6; i <= 100; i++) dp[i] = dp[i - 5] + dp[i - 1];
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << dp[n] << "\n";
    }
    return 0;
}