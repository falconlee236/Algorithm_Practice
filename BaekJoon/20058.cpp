/*
1. 각 위치 index 구하기
2. 90도 회전하기
3. 모든 경우에 대해서 상하좌우 확인 후 얼음이 있는 칸 3개 또는 그 이상과 인접해있지 않은 칸은 얼음의 양이 1 줄어든다
즉 얼음 개수가 2개 이하이면 양이 준다
가생이는 사라지나요? -> 당연히 사라진다
4. 한 연산 이후에 BFS 돌려서 가장 크게 연결되어있는 경우 계속 갱신하면 된다.
*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, Q, ans = 0, res = 0; cin >> N >> Q;
    int num = (1 << N);
    int arr[num][num];
    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++) cin >> arr[i][j];
    }
    while (Q--){
        int tmp[num][num];
        memcpy(tmp, arr, sizeof(arr));
        int query; cin >> query;
        int sub_num = (1 << query);
        for(int i = 0; i < num; i+=sub_num){
            for(int j = 0; j < num; j+=sub_num){
                for(int x = 0; x < sub_num; x++){
                    for(int y = 0; y < sub_num; y++) tmp[x + i][y + j] = arr[sub_num - 1 - y + i][x + j];
                }
            }
        }
        // 열음이 녹는 것은 독립적이기 때문에 따로 복사본을 만들어서 그걸 기준으로 녹인다
        memcpy(arr, tmp, sizeof(arr));
        for(int i = 0; i < num; i++){
            for(int j = 0; j < num; j++){
                if (!arr[i][j]) continue;
                int cnt = 0;
                for(int d = 0; d < 4; d++){
                    int nx = i + dx[d], ny = j + dy[d];
                    if (nx < 0 || nx >= num || ny < 0 || ny >= num || arr[nx][ny] == 0) continue;
                    cnt++;
                }
                if (cnt <= 2) tmp[i][j]--;
            }
        }
        memcpy(arr, tmp, sizeof(arr));
    }
    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++) ans += arr[i][j];
    }
    queue<pair<int, int>> q;
    int tmp_ans = 0;
    int visit[num][num]; memset(visit, 0, sizeof(visit));
    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){
            if (visit[i][j] || !arr[i][j]) continue;
            q.push({i, j});
            visit[i][j] = 1;
            int tmp_res = 0;
            while (q.size()){
                auto cur = q.front(); q.pop();
                tmp_res++;
                for(int d = 0; d < 4; d++){
                    int nx = cur.first + dx[d], ny = cur.second + dy[d];
                    if (nx < 0 || nx >= num || ny < 0 || ny >= num || visit[nx][ny] || !arr[nx][ny]) continue;
                    visit[nx][ny] = visit[cur.first][cur.second] + 1;
                    q.push({nx, ny});
                }
            }
            res = max(res, tmp_res);
        }
    }
    cout << ans << "\n" << res;
}



/*
회전하고 평행이동하면 된다 ㅠㅠ
n - 1 - y, x 원래 전체 히전
x, y → n - y - 1,  x
좌상단 x좌표 + (n - 1 - y), 좌상단 y좌표 + x
그냥 회전하고 평행이동하면 되는구나

n = 4, sub_n = 2  n - 1 - y, sub_num - x
(0, 2) -> (1, 2)
(0, 3) -> (0, 2)
(1, 2) -> (1, 3)
(1, 3) -> (0, 3)

(0, 0) -> (1, 0)
(0, 1) -> (0, 0)
(1, 0) -> (1, 1)
(1, 1) -> (0, 1)

(2, 0) -> (3, 0)
(2, 1) -> (2, 0)
(3, 0) -> (3, 1)
(3, 1) -> (2, 1)


(0, 0) (0, 1) (0, 2) (0, 3)
(1, 0) (1, 1) (1, 2) (1, 3)
(2, 0) (2, 1) (2, 2) (2, 3)
(3, 0) (3, 1) (3, 2) (3, 3)

90도 -> x, y => n(3) - 1 - y, x
(1, 0) (0, 0) (1, 2) (0, 2)
(1, 1) (0, 1) (1, 3) (0, 3)
(3, 0) (2, 0) (3, 2) (2, 2)
(3, 1) (2, 1) (3, 3) (2, 3)

*/