/*2644*/
/*Cheating*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool visit[101];

int main(){
    int n; cin >> n;
    vector<vector<int>> g(n + 1);
    int x, y; cin >> x >> y;
    int m; cin >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    queue<pair<int, int>> q;
    q.emplace(x, 0);
    while(!q.empty()){
        int cur = q.front().first;
        int dist = q.front().second;
        if(cur == y){
            cout << dist;
            return 0;
        }
        q.pop();
        visit[cur] = true;
        for(int i = 0; i < g[cur].size(); i++){
            int next = g[cur][i];
            if(!visit[next]){
                q.emplace(next, dist + 1);
                visit[next] = true;
            }
        }
    }
    cout << -1;
    return 0;
}