#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, Q; cin >> n >> Q;
    vector<pair<int, int>> g[n + 1];
    for(int i = 0; i < n - 1; i++){
        int p, q, r; cin >> p >> q >> r;
        g[p].push_back({q, r});
        g[q].push_back({p, r});
    }
    while(Q--){
        vector<int> visit(n + 1);
        queue<pair<int, int>> q;
        int k, v; cin >> k >> v;
        int ans = 0;
        q.push({v, INT_MAX});
        visit[v] = 1;
        while (q.size()){
            int cur = q.front().first;
            int usado = q.front().second;
            q.pop();
            for(auto [x, y] : g[cur]){
                if (visit[x] == 0){
                    int tmp = min(y, usado);
                    visit[x] = 1;
                    if (tmp >= k) ans++;
                    q.push({x, tmp});
                }
            }
        }
        cout << ans << "\n";
    }
}