#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<vector<int> > v((n + 1) * 3);
    vector<pair<int, int> > ans;
    for(int i = 0; i < n * 3; i++){
        int num; cin >> num;
        v[num].push_back(i);
        if(v[num].size() == 2) ans.emplace_back(i, num);
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i < n; i++) cout << ans[i].second << " ";
    return 0;
}