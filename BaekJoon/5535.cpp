/*5535*/
/*Got it!*/
/*01:02:47*/
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int dp[201][201], arr[201][3], temp[201];
int d, n; 
int solve(int day, int prev){
    if(day == d) return 0;
    int& ret = dp[day][prev];
    if(ret != -1) return ret;
    for(int i = 0; i < n; i++){
        if(arr[i][0] <= temp[day] && temp[day] <= arr[i][1]){
            ret = max(ret, solve(day + 1, i) + abs(arr[prev][2] - arr[i][2]));
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> d >> n;
    for(int i = 0; i < d; i++) cin >> temp[i];
    for(int i = 0; i < n; i++) cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    fill(dp[0], dp[0] + 201 * 201, -1);
    solve(0, 0);
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, dp[1][i]);
    }
    cout << ans;
    return 0;
}