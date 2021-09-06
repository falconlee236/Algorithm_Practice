#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int arr[101][101] = {};
        int dp[101][101] = {};
        int n; cin >> n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) cin >> arr[i][j];
        }
        
        dp[0][0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int jump = arr[i][j];
                if(i + jump < n){
                    if(!dp[i + jump][j]) dp[i + jump][j] = dp[i][j];
                }
                if(j + jump < n){
                    if(!dp[i][j + jump]) dp[i][j + jump] = dp[i][j];
                }
            }
        }
        cout << (dp[n - 1][n - 1] == 0 ? "NO" : "YES") << "\n";
    }

    return 0;
}