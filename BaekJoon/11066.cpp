/*11066*/
/*Cheating*/
#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int page[501];
int sum[501];
int dp[501][501];
int n;

int func(int s, int e){
    int& ret = dp[s][e];
    if(ret != INF) return ret;
    if(s == e) return dp[s][s] = 0;
    if(e - s == 1) return dp[s][e] = page[s] + page[e];
    for(int i = s; i < e; i++){
        ret = min(ret, func(s, i) + func(i + 1, e));
    }
    return ret += sum[e] - sum[s - 1];
}

int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        fill(dp[0], dp[0] + 501 * 501, INF);
        for(int i = 1; i <= n; i++){
            cin >> page[i];
            sum[i] = sum[i - 1] + page[i];
        }
        cout << func(1, n) << "\n";
    }
}