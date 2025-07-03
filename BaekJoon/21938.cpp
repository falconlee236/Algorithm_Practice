#include <iostream>
#include <queue>
using namespace std;
bool visit[1001][1001];
int arr[1001][1001];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m, t, ans = 0; cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m * 3; j+=3) {
            int res = 0, tmp;
            for(int k = 0; k < 3; k++) {
                cin >> tmp;
                res += tmp;
            }
            arr[i][j / 3] = res / 3;
        }
    }
    cin >> t;
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (visit[i][j] || arr[i][j] < t) continue;
            queue<pair<int, int>> q;
            q.push({i, j});
            visit[i][j] = true;
            while (q.size()){
                auto cur = q.front();
                q.pop();
                for(int k = 0; k < 4; k++){
                    int nx = cur.first + dx[k], ny = cur.second + dy[k];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || visit[nx][ny] || arr[nx][ny] < t) continue;
                    visit[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
            ans++;
        }
    }
    cout << ans;   
}
// https://www.acmicpc.net/problem/21938