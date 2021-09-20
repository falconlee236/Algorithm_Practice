/*1904*/
/*Got it!*/
/*06:58*/
#include <iostream>
using namespace std;

int dp[1000001];
int solve(int n){
    if(n == 0 || n == 1) return 1;
    int& ret = dp[n];
    if(ret != 0) return ret;
    return ret = (solve(n - 1) + solve(n - 2)) % 15746;
}

int main(){
    int n; cin >> n;
    cout << solve(n) % 15746;
    return 0;
}