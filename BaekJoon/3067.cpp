#include <iostream>
#include <vector>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while (T--){
		int n, m, num; cin >> n;
		vector<int> dp(10001, 0); dp[0] = 1;
		while(n--){
			cin >> num;
			for(int i = 1; i <= 10000; i++){
				if (i < num) continue;
				dp[i] += dp[i - num];
			}
		}
		cin >> m;
		cout << dp[m] << "\n";
	}
}