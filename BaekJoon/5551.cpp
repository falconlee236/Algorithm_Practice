#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k, a, b, l, ans = 0; cin >> n >> m >> k;
    vector<vector<pair<int, int>>> graph(n + 1);
    for(int i = 0; i < m; i++){
        cin >> a >> b >> l;
        graph[a].push_back({b, l});
        graph[b].push_back({a, l});
    }
    vector<int> dist(n + 1, 0xFFFFFFF);
    priority_queue<pair<int, int>> pq;
    for(int i = 0; i < k; i++){
        int s; cin >> s;
        dist[s] = 0;
        pq.push({0, s});
    }
    while(pq.size()){
        auto [cost, node] = pq.top();
        cost = -cost;
        pq.pop();
        if (dist[node] < cost) continue;
        for(auto [x, y] : graph[node]){
            if (cost + y < dist[x]){
                dist[x] = cost + y;
                pq.push({-dist[x], x});
            }
        }
    }
    for(int u = 1; u <= n; u++){
        for(auto [v, w]: graph[u]) ans = max(ans, (dist[u] + dist[v] + w + 1) / 2);
    }
    cout << ans;
}