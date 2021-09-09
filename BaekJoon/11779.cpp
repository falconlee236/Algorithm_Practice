/*11779*/
/*Cheating*/
#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;

int s, e;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> dist(n + 1, INF);
    vector<vector<pair<int, int>>> g(n + 1);
    vector<int> route(n + 1, INF);
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
    cin >> s >> e;
    
    priority_queue<pair<int, int>> pq;
    pq.push({0, s});
    dist[s] = 0;
    route[s] = 0;
    while(!pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(cost > dist[cur]) continue;
        for(int i = 0; i < g[cur].size(); i++){
            int next = g[cur][i].first;
            int nextdist = cost + g[cur][i].second;
            if(dist[next] > nextdist){
                dist[next] = nextdist;
                pq.push({-nextdist, next});
                route[next] = cur;
            }
        }
    }
    cout << dist[e] << "\n";
    int cnt = 0;
    int node = route[e];
    vector<int> ans;
    while(node){
        ans.push_back(node);
        node = route[node];
        cnt++;
    }
    cout << cnt + 1 << "\n";
    for(int i = ans.size() - 1; i >= 0 ; i--) cout << ans[i] << " ";
    cout << e;
    return 0;
}