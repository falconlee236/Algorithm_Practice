#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int sea[302][302];
int check[302][302];
int vi[302][302];
int x_pos[4] = {0, 1, 0, -1};
int y_pos[4] = {1, 0, -1, 0};
int n, m;

void bfs(int x, int y){
    queue<pair<int, int>> q;

    q.push({x, y});
    vi[x][y] = 1;
    while(q.size()){
        int x_cur = q.front().first;
        int y_cur = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int x_next = x_cur + x_pos[i];
            int y_next = y_cur + y_pos[i];
            if (x_next >= 0 and x_next < n 
                    and y_next >= 0 and y_next < m
                    and !vi[x_next][y_next] and sea[x_next][y_next]){
                vi[x_next][y_next] = 1;
                q.push({x_next, y_next});
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin >> sea[i][j];
    while (1){
        int cnt = 0, ans = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if (sea[i][j] == 0){
                    cnt++;
                    continue;
                }
                for(int k = 0; k < 4; k++){
                    int x_next = i + x_pos[k];
                    int y_next = j + y_pos[k];
                    if (x_next >= 0 and y_next >= 0 
                        and x_next < n and y_next < m
                        and sea[x_next][y_next] == 0)
                        check[i][j]++;
                }
            }
        }
        if (cnt == n * m){
            cout << 0 << "\n";
            return 0;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                sea[i][j] -= check[i][j];
                if (sea[i][j] < 0)
                    sea[i][j] = 0;
            }
        }
        int div = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if (sea[i][j] != 0 and !vi[i][j]){
                    bfs(i, j);
                    div++;
                }
            }
        }
        ans++;
        if (div > 1){
            cout << ans << "\n";
            return 0;
        }
        memset(vi, 0, sizeof(vi));
        memset(check, 0, sizeof(check));
    }
}