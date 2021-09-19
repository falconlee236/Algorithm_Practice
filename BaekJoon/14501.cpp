/*14501*/
/*Cheating*/
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int t[16], p[16], dp[16];

int solve(int pos){
    if(pos == n) return 0;
    if(pos > n) return -987654321;
    int& ret = dp[pos];
    if(ret != -1) return ret;
    ret = max(solve(pos + 1), solve(pos + t[pos]) + p[pos]);
    return ret;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> t[i] >> p[i];
    fill(dp, dp + 16, -1);
    cout << solve(0);
    return 0;
}