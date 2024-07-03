#include <iostream>
#include <vector>
using namespace std;
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<pair<int, pair<int, int>>> edges;
    vector<long long> dist(n + 1, INT32_MAX);
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        edges.push_back({a, {b, c}});
    }
    dist[1] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int from = edges[j].first, to = edges[j].second.first, cost = edges[j].second.second;
            if (dist[from] == INT32_MAX) continue;
            if (dist[to] > dist[from] + cost){
                if (i == n - 1){
                    cout << -1;
                    return 0;
                }
                dist[to] = dist[from] + cost;
            }
        }
    }
    for(int i = 2; i < n + 1; i++)
        cout << (dist[i] == INT32_MAX ? -1 : dist[i]) << "\n";
}