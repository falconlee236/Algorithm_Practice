/*1238*/
/*Got it!*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

vector<vector<pair<int, int>>> g;

void dijkstra(vector<int>& d, int start){
    priority_queue<pair<int, int>> pq;
    pq.emplace(0, start);
    d[start] = 0;
    while(!pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(cost > d[cur]) continue;
        for(int i = 0; i < g[cur].size(); i++){
            int next = g[cur][i].first;
            int nextdist = cost + g[cur][i].second;
            if(d[next] > nextdist){
                pq.emplace(-nextdist, next);
                d[next] = nextdist;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, x; cin >> n >> m >> x;
    int ans[1002] = {};
    g = vector<vector<pair<int, int>>>(n + 1);
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
    for(int i = 1; i <= n; i++){
        vector<int> dist1(n + 1, INF);
        dijkstra(dist1, i);
        ans[i] = dist1[x];
    }
    vector<int> dist(n + 1, INF);
    dijkstra(dist, x);
    int res = -1;
    for(int i = 1; i <= n; i++){
        res = max(res, dist[i] + ans[i]);
    }
    cout << res;
    return 0;
}