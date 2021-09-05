/*1916*/
/*Got it*/
#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> g(n + 1);
    vector<int> dist(n + 1, INF);
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
    int start, end; cin >> start >> end;
    priority_queue<pair<int, int>> pq;
    pq.emplace(0, start);
    dist[start] = 0;
    while(!pq.empty()){
        int cost = -pq.top().first, cur = pq.top().second;
        pq.pop();
        if(cost > dist[cur]) continue;
        for(int i = 0; i < g[cur].size(); i++){
            int next = g[cur][i].first;
            int nextdist = cost + g[cur][i].second;
            if(dist[next] > nextdist){
                dist[next] = nextdist;
                pq.emplace(-nextdist, next);
            }
        }
    }
    cout << dist[end];
    return 0;
}