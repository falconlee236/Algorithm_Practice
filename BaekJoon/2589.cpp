#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int row, col;
int v[52][52];
char b_map[52][52];
int x_pos[4] = {0, 1, 0, -1};
int y_pos[4] = {1, 0, -1, 0};

int bfs(int x, int y){
    int tmp = 0;
    queue<pair<int, int>> q;

    q.push({x, y});
    v[x][y] = 1;
    while (q.size()){
        int cur_x = q.front().first;
        int cur_y = q.front().second;

        q.pop();
        tmp = max(tmp, v[cur_x][cur_y]);
        for(int i = 0; i < 4; i++){
            int next_x = cur_x + x_pos[i];
            int next_y = cur_y + y_pos[i];
            if (next_x >= 0 and next_y >= 0 and next_x < row and next_y < col){
                if (v[next_x][next_y] == 0 and b_map[next_x][next_y] == 'L'){
                    q.push({next_x, next_y});
                    v[next_x][next_y] = v[cur_x][cur_y] + 1;
                }
            }
        }
    }
    return tmp;
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int res = 0;
    cin >> row >> col;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++)
            cin >> b_map[i][j];
    }
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if (b_map[i][j] == 'L'){
                res = max(bfs(i, j) - 1, res);
                memset(v, 0, sizeof(v));
            }
        }
    }
    cout << res << "\n";
}