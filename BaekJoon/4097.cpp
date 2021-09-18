/*4097*/
/*Cheating*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(1){
        int n; cin >> n;
        int dp[250010] = {};
        if(!n) break;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];
        dp[0] = arr[0];
        int ans = dp[0];
        for(int i = 1; i < n; i++){
            dp[i] = max(dp[i - 1] + arr[i], arr[i]);
            ans = max(ans, dp[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}