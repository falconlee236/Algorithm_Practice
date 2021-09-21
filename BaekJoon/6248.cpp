/*6248*/
/*Got it!*/
/*21:24*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, x; cin >> n >> m >> x;
    vector<int> dist(n + 1 , INF);
    vector<vector<pair<int, int>>> g(n + 1);
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    
    priority_queue<pair<int, int>> pq;
    pq.emplace(0, x);
    dist[x] = 0;
    while(!pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(cost < dist[cur]) continue;
        for(int i = 0; i < g[cur].size(); i++){
            int next = g[cur][i].first;
            int nextdist = cost + g[cur][i].second;
            if(nextdist < dist[next]){
                pq.emplace(-nextdist, next);
                dist[next] = nextdist;
            }
        }
    }
    int ans = *max_element(dist.begin() + 1, dist.end());
    cout << ans * 2;
    return 0;
}