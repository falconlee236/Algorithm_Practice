#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m, r, c, ans = 1e9; cin >> n >> m >> r >> c;
    int arr[n + 1][m + 1], visit[n + 1][m + 1];
    memset(arr, 0, sizeof(arr));
    memset(visit, 0, sizeof(visit));
    for(int i = 0; i < r; i++){
        int a, b, c; cin >> a >> b >> c;
        arr[a][b] = c;
    }
    queue<pair<pii, int>> q;
    for(int i = 0; i < c; i++){
        int a, b; cin >> a >> b;
        q.push({{a, b}, 0});
        visit[a][b] = 1;
    }
    while (q.size()){
        auto tmp = q.front();
        q.pop();
        int cx = tmp.first.first, cy = tmp.first.second, cost = tmp.second;
        if (arr[cx][cy]) ans = min(ans, cost * arr[cx][cy]);
        for(int i = 0; i < 4; i++){
            int nx = cx + dx[i], ny = cy + dy[i];
            if (0 < nx && nx <= n && 0 < ny && ny <= m && !visit[nx][ny]){
                visit[nx][ny] = 1;
                q.push({{nx, ny}, cost + 1});
            }
        }
    }
    cout << ans;
}