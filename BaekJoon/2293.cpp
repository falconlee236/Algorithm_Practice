#include <iostream>
using namespace std;
int dp[10001];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k; dp[0] = 1;
    int arr[n]; for(int &x : arr) cin >> x;
    for(int x : arr) for(int i = x; i <= k; i++) dp[i] += dp[i - x];
    cout << dp[k];
}