#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int N, M, K;
struct fireball{
    int x, y, mess, speed, dir;
};
int get_next_pos(int pos){
    if (pos < 1) return (pos % N) + N;
    if (pos > N) return (pos % N == 0 ? N : pos % N);
    return pos;
}
vector<fireball> arr[60][60];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M >> K;
    queue<fireball> q;
    while (M--){
        int r, c, m, s, d; cin >> r >> c >> m >> s >> d;
        q.push({r, c, m, s, d});
    }
    while (K--){
        while (q.size()){
            auto cur = q.front(); q.pop();
            int x = cur.x, y = cur.y, mess = cur.mess, speed = cur.speed, dir = cur.dir;
            int nx = get_next_pos(x + dx[dir] * speed), ny = get_next_pos(y + dy[dir] * speed);
            arr[nx][ny].push_back({nx, ny, mess, speed, dir});
        }
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++) {
                if (arr[i][j].size() == 0) continue;
                if (arr[i][j].size() == 1) {
                    q.push(arr[i][j].front());
                    continue;
                }
                int mess = 0, speed = 0, dir_cnt = 0;
                for(auto node : arr[i][j]){
                    mess += node.mess;
                    speed += node.speed;
                    dir_cnt += (node.dir % 2);
                }
                mess /= 5;
                speed /= arr[i][j].size();
                if (mess == 0) continue;
                if (dir_cnt == 0 || dir_cnt == arr[i][j].size()){
                    for(int d = 0; d < 8; d+=2) q.push({i, j, mess, speed, d});
                } else {
                    for(int d = 1; d < 8; d+=2) q.push({i, j, mess, speed, d});
                }
            }
        }
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                arr[i][j].clear();
            }
        }
    }
    int ans = 0;
    while (q.size()){
        auto node = q.front(); q.pop();
        ans += node.mess;
    }
    cout << ans;
}