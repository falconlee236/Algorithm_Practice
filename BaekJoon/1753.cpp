/*1753*/
/*Cheating*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int main(){
    int v, e; cin >> v >> e;
    int start; cin >> start;
    vector<vector<pair<int, int>>> g(v + 1);
    vector<int> dist(v + 1, INF);
    for(int i = 0 ; i < e; i++){
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
    priority_queue<pair<int, int>> pq;
    pq.emplace(0, start);
    dist[start] = 0;
    while(!pq.empty()){
        int node = pq.top().second, cost = -pq.top().first;
        pq.pop();
        if(cost > dist[node]) continue;
        for(int i = 0; i < g[node].size(); i++){
            int next = g[node][i].first;
            int nextdist = cost + g[node][i].second;
            if(dist[next] > nextdist){
                dist[next] = nextdist;
                pq.emplace(-nextdist, next);
            }
        }
    }
    for(int i = 1; i <= v; i++){
        if(dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
    return 0;
}
