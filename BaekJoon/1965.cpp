#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int arr[n];
    vector<int> dp(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    dp[0] = 1;
    for(int i = 1; i < n; i++){
        for(int j = i - 1; j >= 0; j--){
            if (arr[j] < arr[i]) dp[i] = max(dp[i], dp[j]);
        }
        dp[i]++;
    }
    cout << *max_element(dp.begin(), dp.end()) << "\n";
}