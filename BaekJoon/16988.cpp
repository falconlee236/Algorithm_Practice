#include <iostream>
#include <cstring>
using namespace std;
int n, m, arr[25][25], visited[25][25], ans = 0, tmp = 0, base = 0;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
void solve(int x, int y){
    int cnt = 0;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if (arr[nx][ny] != 0 || (arr[nx][ny] == 0 && (nx == 0 || nx == n + 1 || ny == 0 || ny == m + 1) )) cnt++;
    }
    if (cnt == 4) tmp++;
    else tmp = 0;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if (arr[nx][ny] != 2 || visited[nx][ny]) continue;
        visited[nx][ny] = 1;
        base++;
        solve(nx, ny);
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) cin >> arr[i][j];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if (arr[i][j]) continue;
            arr[i][j] = 1;
            for(int a = 1; a <= n; a++){
                for(int b = 1; b <= m; b++){
                    if (arr[a][b]) continue;
                    arr[a][b] = 1;
                    int res = 0;
                    for(int x = 1; x <= n; x++){
                        for(int y = 1; y <= m; y++){
                            if (arr[x][y] != 2 || visited[x][y]) continue;
                            visited[x][y] = 1;
                            base++;
                            solve(x, y);
                            if (tmp == base) res += tmp;
                            tmp = 0, base = 0;
                        }   
                    }
                    arr[a][b] = 0;
                    memset(visited, 0, sizeof(visited));
                    ans = max(ans, res);
                }
            }
            arr[i][j] = 0;
        }
    }
    cout << ans;
}