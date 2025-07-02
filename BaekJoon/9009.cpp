#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int dp[45];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    dp[1] = 1, dp[2] = 1;
    for(int i = 3; i <= 45; i++) dp[i] = dp[i - 1] + dp[i - 2];
    while(T--){
        int num; cin >> num;
        vector<int> v;
        for(int i = 45; i >= 1; i--){
            if (num >= dp[i]) {
                v.push_back(dp[i]);
                num-=dp[i];
            }
        }
        for(int i = v.size() - 1; i >= 0; i--) cout << v[i] << " ";
        cout << "\n";
    }
}