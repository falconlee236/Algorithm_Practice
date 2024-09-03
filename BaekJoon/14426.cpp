#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m, ans = 0; cin >> n >> m;
    vector<string> arr(n); for(auto &x: arr) cin >> x;
    sort(arr.begin(), arr.end());
    for(int i = 0; i < m; i++){
        int cnt = 0;
        string target; cin >> target;
        auto it = lower_bound(arr.begin(), arr.end(), target);
        if (it == arr.end()) continue;
        string s = *it;
        for(size_t j = 0; j < target.size() && j < s.size(); j++){
            if (s[j] == target[j]) cnt++;
        }
        ans += (cnt == target.size());
    }
    cout << ans;
}