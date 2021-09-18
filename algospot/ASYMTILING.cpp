#include <iostream>
#include <algorithm>
#define DIV 1000000007
using namespace std;

int dp[101], ddp[101];

int solve_sym(int num){
    if(num == 1 || num == 0) return 1;
    int& ret = dp[num];
    if(ret != -1) return ret;
    return ret = (solve_sym(num - 2) + solve_sym(num - 1)) % DIV;
}

int asymmetric(int num){
    if(num % 2 == 1) return (solve_sym(num) - solve_sym(num / 2) + DIV) % DIV;
    int ret = solve_sym(num);
    ret = (ret - solve_sym(num / 2) + DIV) % DIV;
    ret = (ret - solve_sym(num / 2 - 1) + DIV) % DIV;
    return ret;
}

int main(){
    int t; cin >> t;
    while(t--){
        fill(dp, dp + 101, -1);
        fill(ddp, ddp + 101, -1);
        int n; cin >> n;
        cout << asymmetric(n) << "\n";
    }
    return 0;
}