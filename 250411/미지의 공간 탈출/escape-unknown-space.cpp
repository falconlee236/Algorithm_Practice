#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
#define EA 0 // 0001
#define WE 1 // 0010
#define SO 2 // 0100
#define NO 3 // 1000
#define TO 4
#define BO 5
using namespace std;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int arr[30][30];
bool arr_visit[30][30];
int cube[5][20][20];
bool cube_visit[5][20][20];
int sit[20][4];
int n, m, f, ans;
/*
EA -> 0, 1
WE -> 0, -1
SO -> 1, 0
NO -> -1, 0
*/


int get_border(int x, int y){
    if (x == 0 && y == 0) return (1 << NO) | (1 << WE);
    if (x == 0 && y == m - 1) return (1 << NO) | (1 << EA);
    if (x == m - 1 && y == 0) return (1 << SO) | (1 << WE);
    if (x == m - 1 && y == m - 1) return (1 << SO) | (1 << EA);
    if (x == 0) return (1 << NO);
    if (x == m - 1) return (1 << SO);
    if (y == 0) return (1 << WE);
    if (y == m - 1) return (1 << EA);
    return 0;
}

bool check_valid(int nx, int ny, string std, int type){
    if (std == "arr") return (nx < 0 || nx >= n || ny < 0  || ny >= n || arr_visit[nx][ny]);
    else return (nx < 0 || nx >= m || ny < 0  || ny >= m || cube_visit[type][nx][ny]);
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> f;
    int s_x = 200, s_y = 200, e_x = 0, e_y = 0;
    queue<tuple<int, int, int, int>> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1 || arr[i][j] == 3) {
                arr_visit[i][j] = true;
                if (arr[i][j] == 3) {
                    s_x = min(s_x, i);
                    s_y = min(s_y, j);
                    e_x = max(e_x, i);
                    e_y = max(e_y, j);
                }
            }
        }
    }
    for(int t = 0; t < 5; t++){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++) {
                cin >> cube[t][i][j];
                if (cube[t][i][j] == 1) cube_visit[t][i][j] = true;
            }
        }
    }
    
    for(int i = 1; i <= f; i++) {
        cin >> sit[i][0] >> sit[i][1] >> sit[i][2] >> sit[i][3];
        q.push({-i, sit[i][0], sit[i][1], 1});
        arr_visit[sit[i][0]][sit[i][1]] = true;
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            if (cube[TO][i][j] == 2) {
                q.push({TO, i, j, 0});
                cube_visit[TO][i][j] = true;
            }
        }
    }

    while (q.size() > 0){
        int type, x, y, cost; tie(type, x, y, cost) = q.front(); q.pop();
        if (type == BO && arr[x][y] == 4){
            cout << cost;
            return 0;
        }
        // 이상현상
        if (type < 0) {
            int sit_type = -type;
            if (cost % sit[sit_type][3] != 0) {
                q.push({type, x, y, cost + 1});
                continue;
            }
            int nx = x + dx[sit[sit_type][2]], ny = y + dy[sit[sit_type][2]];
            if (check_valid(nx, ny, "arr", 0) || arr[nx][ny] == 4) continue;
            q.push({type, nx, ny, cost + 1});
            arr_visit[nx][ny] = true;
            continue;
        }
        int border = get_border(x, y);
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if (type == BO) {
                if (check_valid(nx, ny, "arr", type)) continue;
                q.push({type, nx, ny, cost + 1});
                arr_visit[nx][ny] = true;
            }
            else {
                if ((check_valid(nx, ny, "cube", type))){
                    if ((border & (1 << i)) == 0) continue;
                    int next_type, nx, ny;
                    if (i == EA){
                        if (type == EA) next_type = NO;
                        else if (type == WE) next_type = SO;
                        else if (type == SO) next_type = EA;
                        else if (type == NO) next_type = WE;
                        else next_type = EA;

                        nx = (type != TO ? x : 0);
                        ny = (type != TO ? 0 : m - x - 1);                 
                    } else if (i == WE) {
                        if (type == EA) next_type = SO;
                        else if (type == WE) next_type = NO;
                        else if (type == SO) next_type = WE;
                        else if (type == NO) next_type = EA;
                        else next_type = WE;
                        
                        nx = (type != TO ? x : 0);
                        ny = (type != TO ? 0 : x);
                    } else if (i == SO) {
                        if (type == TO) next_type = SO;
                        else next_type = BO;

                        if (type == TO) nx = 0, ny = y;
                        else if (type == EA) nx = e_x - y, ny = e_y + 1;
                        else if (type == WE) nx = s_x + y, ny = s_y - 1;
                        else if (type == SO) nx = e_x + 1, ny = s_y + y;
                        else if (type == NO) nx = s_x - 1, ny = e_y - y;
                    } else {
                        if (type == TO) next_type = NO;
                        else next_type = TO;

                        if (type == TO) nx = 0, ny = m - 1 - y;
                        else if (type == EA) nx = m - 1 - y, ny = m - 1;
                        else if (type == WE) nx = y, ny = 0;
                        else if (type == SO) nx = m - 1, ny = y;
                        else if (type == NO) nx = 0, ny = m - 1 - y;
                    }
                    if (next_type != BO){
                        if (cube_visit[next_type][nx][ny]) continue;
                        cube_visit[next_type][nx][ny] = true;    
                    } else {
                        if (arr_visit[nx][ny]) continue;
                        arr_visit[nx][ny] = true;
                    }
                    q.push({next_type, nx, ny, cost + 1});
                    continue;
                }
                q.push({type, nx, ny, cost + 1});
                cube_visit[type][nx][ny] = true;   
            }
        }
    }
    cout << -1;
}