// https://www.codetree.ai/ko/frequent-problems/problems/ancient-ruin-exploration/description
/*
5 * 5, 각 칸에는 1~7까지 숫자 <- 유물조각
1. 회전축을 아무거나 잡은 다음 그걸 기준으로 90도, 180도, 270도 중 하나 선택해서 회전 (평행이동!)

-> 열 부터 확인해야 한다는것이 핵심 (놓치지마라) (왼쪽에서 오른쪽으로, 위에서 아래로)

유물 1차 획득
그냥 bfs로 같은 숫자끼리 <3개 이상> 이어져 있는 경우
이때 가치는 모인 조각의 <개수>

유물이 사라지면 벽면에 써있는 숫자대로 조각이 다시 생성
조건은 (왼쪽에서 오른쪽으로, 아래에서 위로)
1. 열 번호가 작은 순으로,
2. 행 번호가 큰 순으로 <- ㅋㅋ 이렇게 낚시를 건다고?
단 생겨날 조각의 수는 부족하지 않음

한번쓰면 유물조각 다시 사용 불가 이후는 남은 숫자부터 사용
유물조각이 생성되면 계속 유물을 얻을 수 있고, 더이상 못 얻을때까지 수행

이 과정을 K번 수행함. 출력은 해당 턴에 얻을 수 있는 유물 가치의 총합을 각각 공백으로 출력
유물을 얻을 수 없으면 출력하지 않고 프로그램 종료
1. 회전축 찾기
1 - 2. 회전 돌리기 90(시계), 180(반대로), 270(반시계)
2. 조건에 맞춰 회전축 + 방향까지 선택하기
2 - 1. 유물 찾고 칸 없애기
2 - 2. 없앤 칸에 유물 채우기 (단 한번 쓴 유물은 게임이 끝날때까지 못씀)
2 - 3. 2 - 1으로 반복 -> before, after가 같을 때 까지
3. 모두 0이면 종료
*/
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int tmp_arr[5][5], arr[5][5];
int block[350];
int block_idx, K, M;
/*
조건 
(1) 유물 1차 획득 가치 최대화
(2) 90도, 180도, 270도 순으로 우선순위 (가장 작은게 높음)
(3) 회전 중심 좌표의 열이 가장 작음
(4) 회전 중심 좌표의 행이 가장 작음
*/
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