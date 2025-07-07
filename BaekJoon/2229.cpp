#include <iostream>
using namespace std;
int arr[10001], dp[10001]; // dp[i] = 현재 시점에서 조원이 i명일때 최대값
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for(int &x : arr) cin >> x;
    for(int i = 0; i < n; i++){
        int mx, mn;
        mx = mn = arr[i];
        for(int j = i; j >= 0; j--){
            mn = min(mn, arr[j]);
            mx = max(mx, arr[j]);
            dp[i + 1] = max(dp[i + 1], dp[j] + mx - mn);
        }
    }
    cout << dp[n];
}
// https://beginthread.tistory.com/144