#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int n, b, ans = 0; cin >> n >> b;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end(), [](auto &a, auto &b){
        return a.first + a.second < b.first + b.second;
    });
    for(int i = 0; i < n; i++){
        long long tmp = v[i].first / 2 + v[i].second;
        int tmp_ans = 0;
        if (tmp <= b) tmp_ans++;
        for(int j = 0; j < n; j++){
            if (i == j) continue;
            tmp += v[j].first + v[j].second;
            if (tmp <= b) tmp_ans++;
        }
        ans = max(ans, tmp_ans);
    }
    cout << ans;
}