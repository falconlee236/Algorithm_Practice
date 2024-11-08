#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m, s, e; cin >> n >> m >> s >> e;
    vector<vector<int>> v(n + 1);
    for(int x, y; m--; v[x].push_back(y), v[y].push_back(x)) cin >> x >> y;
    vector<int> visited(n + 1, 0); visited[s] = 1;
    queue<int> q; q.push(s);
    while(q.size()){
        int cur = q.front(); q.pop();
        if (cur == e){
            cout << visited[cur] - 1;
            break;
        }
        if (cur > 0 && !visited[cur - 1]) visited[cur - 1] = visited[cur] + 1, q.push(cur - 1);
        if (cur < n && !visited[cur + 1]) visited[cur + 1] = visited[cur] + 1, q.push(cur + 1);
        for(int next : v[cur]){
            if (visited[next]) continue;
            visited[next] = visited[cur] + 1;
            q.push(next);
        }
    }
}