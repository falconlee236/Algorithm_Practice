/*1699*/
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int dp[100001];
    int n; cin >> n;
    for(int i = 0; i <= n; i++) dp[i] = i;
    for(int i = 4; i <= n; i++){
        for(int j = 2; j * j <= i; j++){
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    cout << dp[n];
    return 0;
}
