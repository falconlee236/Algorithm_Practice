/*11060*/
/*Got it!*/
/*31:30*/
#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int n;
int arr[1002];
int dp[1002];
int solve(int pos){
    if(pos == n - 1) return 0;
    if(pos >= n) return INF;
    int& ret = dp[pos];
    if(ret != -1) return ret;
    ret = INF;
    for(int i = 1; i <= arr[pos]; i++){
        ret = min(ret, solve(pos + i) + 1);
    }
    return ret;
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i];
	fill(dp, dp + 1002, -1);
	int ans = solve(0);
	cout << (ans == INF ? -1 : ans);
	return 0;
}
