#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<vector<int>> g(n + 1);
        vector<int> cnt(n + 1);
        set<int> s;
        for(int i = 1; i <= n; i++){
            int num; cin >> num;
            cnt[i] = num;
            if(num == 0) s.insert(i);
            while(num--){
                int p; cin >> p;
                g[p].push_back(i);
            }
        }
        
        int total = n;
        int p = 1, ans = 1;
        bool flag = true;
        while(total > 0){
            if(!s.size()){
                cout << -1 << "\n";
                flag = false;
                break;
            }
            auto it = s.lower_bound(p);
            if(it == s.end()){
                ans++;
                p = 1;
            }else{
                int idx = *it;
                s.erase(it);
                for(int i = 0; i < g[idx].size(); i++){
                    int next = g[idx][i];
                    cnt[next]--;
                    if(!cnt[next]) s.insert(next);
                }
                p = idx;
                total--;
            }
        }
        if(flag) cout << ans << "\n";
    }
	return 0;
}