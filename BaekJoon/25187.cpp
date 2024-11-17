#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m, q; cin >> n >> m >> q;
    int arr[n + 1], visited[n + 1], cost[n + 1], group[n + 1];
    for(int i = 1; i <= n; i++) cin >> arr[i], visited[i] = 0, cost[i] = 0, group[i] = 0;
    vector<vector<int>> g(n + 1);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        g[a].push_back(b), g[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        if (visited[i]) continue;
        queue<int> q;
        q.push(i), visited[i] = 1, group[i] = i;
        cost[i] += (arr[i] ? 1 : -1);
        while (q.size()){
            int cur = q.front();
            q.pop();
            for(int next : g[cur]){
                if (visited[next]) continue;
                q.push(next), visited[next] = 1, group[next] = i;
                cost[i] += (arr[next] ? 1 : -1);
            }
        }
    }
    while(q--){
        int query; cin >> query;
        cout << (cost[group[query]] > 0 ? 1 : 0) << "\n";
    }
}