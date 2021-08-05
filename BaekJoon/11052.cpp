/*11052*/
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    int arr[1001];
    int dp[1001] = {};
    for(int i = 1; i <= n; i++) cin >> arr[i];
    dp[1] = arr[1];
    int res = 0;
    for(int i = 2; i <= n; i++){
        for(int j = i; j > 0; j--){
            dp[i] = max(dp[i], arr[j] + dp[i - j]);
        }
        res = max(res, dp[i]);
    }
    cout << res;
    return 0;
}