#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int tmp_arr[5][5], arr[5][5];
int block[350];
int block_idx, K, M;
struct node{
    int x, y, degree, cost;
    bool operator < (const node& n) const {
        if (cost == n.cost && degree == n.degree && y == n.y) return x > n.x;
        if (cost == n.cost && degree == n.degree) return y > n.y;
        if (cost == n.cost) return degree > n.degree;
        return cost < n.cost;
    }
};
void rot_clockwise(int x, int y){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++) tmp_arr[i + x][j + y] = arr[2 - j + x][i + y];
    }
    memcpy(arr, tmp_arr, sizeof(arr));
}
int do_first(){
    int cost = 0;
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    bool visit[5][5]; memset(visit, 0, sizeof(visit));
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if (visit[i][j]) continue;
            int type = tmp_arr[i][j], tmp_cnt = 1;
            queue<pair<int, int>> q;
            q.push({i, j});
            visit[i][j] = true;
            while (q.size()){
                auto cur = q.front(); q.pop();
                for(int k = 0; k < 4; k++){
                    int nx = cur.first + dx[k], ny = cur.second + dy[k];
                    if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || visit[nx][ny] || tmp_arr[nx][ny] != type) continue;
                    visit[nx][ny] = true;
                    tmp_cnt++;
                    q.push({nx, ny});
                }
            }
            if (tmp_cnt > 2) cost += tmp_cnt;
        }
    }
    return cost;
}
int get_benefit(){
    int cost = 0, tmp_cost = -1;
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    while (tmp_cost != 0){
        bool visit[5][5]; memset(visit, 0, sizeof(visit));
        int cur_arr[5][5]; memset(cur_arr, 0, sizeof(cur_arr));
        tmp_cost = 0;
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                if (visit[i][j] || tmp_arr[i][j] == 0) continue;
                int type = tmp_arr[i][j], tmp_cnt = 1;
                queue<pair<int, int>> q;
                q.push({i, j});
                visit[i][j] = true;
                cur_arr[i][j] = 2;
                // 사라져야하는 부분 기록하고 한번에 지워야함
                while (q.size()){
                    auto cur = q.front(); q.pop();
                    for(int k = 0; k < 4; k++){
                        int nx = cur.first + dx[k], ny = cur.second + dy[k];
                        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || visit[nx][ny] || tmp_arr[nx][ny] != type) continue;
                        visit[nx][ny] = true;
                        cur_arr[nx][ny] = 2;
                        tmp_cnt++;
                        q.push({nx, ny});
                    }
                }
                // 유물인 경우 1로 표시해서 삭제해야함, 유물이 아니면 0으로 다시 바꿔서 삭제 안함
                for(int i = 0; i < 5; i++){
                    for(int j = 0; j < 5; j++){
                        if (cur_arr[i][j] == 2) {
                            cur_arr[i][j] = (tmp_cnt > 2 ? 1 : 0);
                            tmp_cost += (tmp_cnt > 2 ? 1 : 0);
                        }
                    }
                }
            }
        }
        cost += tmp_cost;
        for(int i = 0; i < 5; i++){
            for(int j = 4; j >= 0; j--){
                if (cur_arr[j][i] == 1) tmp_arr[j][i] = block[block_idx++];
            }
        }
    }
    memcpy(arr, tmp_arr, sizeof(arr));
    return cost;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> K >> M;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++) cin >> arr[i][j];
    }
    for(int &x : block) cin >> x;
    priority_queue<node> pq;
    while (K--){
        memcpy(tmp_arr, arr, sizeof(arr));
        pq = priority_queue<node>();
        for(int a = 0; a < 3; a++){
            for(int b = 0; b < 3; b++){
                for(int deg = 90; deg <= 270; deg+=90){
                    rot_clockwise(a, b);
                    pq.push({a, b, deg, do_first()});
                }
                rot_clockwise(a, b);
            }
        }
        auto value = pq.top();
        for(int i = 1; i <= value.degree / 90; i++) rot_clockwise(value.x, value.y);
        int ans = get_benefit();
        if (value.cost == 0) break;
        cout << ans << " ";
    }
}