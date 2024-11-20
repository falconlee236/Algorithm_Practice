#include <iostream>
int dp[11];
using namespace std;
int main(){
    int n; cin >> n;
    for(int i = 2; i <= n; i++) dp[i] = dp[i / 2] + dp[i - i / 2] + ((i / 2) * (i - i / 2));
    cout << dp[n];
}