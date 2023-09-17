#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    priority_queue<pair<int, int>> pq;
    vector<pair<int, int>> v[n + 1];
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        v[a].push_back({c, b});
        v[b].push_back({c, a});
    }
    vector<int> dist(n + 1, 2147483647);
    pq.push({0, 1});
    dist[1] = 0;
    while (pq.size()){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        for(auto x : v[cur]){
            int ncost = x.first;
            int next = x.second;
            if (cost + ncost < dist[next]){
                dist[next] = cost + ncost;
                pq.push({-dist[next], next});
            }
        }
    }
    cout << dist[n];
}