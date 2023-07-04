#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<pair<double, int>> ans; 
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        ans.emplace_back((double)a / (a + b), i + 1);
    }
    sort(ans.begin(), ans.end(),
    [](pair<double, int> &a, pair<double, int> &b) -> bool
    {
        if (a.first == b.first) return false;
        return a.first > b.first;
    });
    for(int i = 0; i < n; i++) cout << ans[i].second << " ";
}