/*11053*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    int arr[1001] = {0, };
    int dp[1001] = {0, };
    
    for(int i = 1; i <= n; i++) cin >> arr[i];
    int res = 0;
    for(int i = 1; i <= n; i++){
        dp[i] = 1;
        for(int j = i - 1; j >= 1; j--){
            if(arr[j] < arr[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
        res = max(res, dp[i]);
    }
    cout << res;
    return 0;
}