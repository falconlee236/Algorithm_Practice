// https://www.codetree.ai/ko/frequent-problems/problems/medusa-and-warriors/description
/*
output
4 2 2
0 2 0
1 1 1
0 0 0
0 0 0
0
<최단경로는 멘헤튼거리 기준!>
0~n-1까지 n * n 마을에 메두사가 있음 도로 = 0, 도로 아니면 1
메두사집은 sr, sc 공원은 er, ec <- 집과 공원은 서로 다름, 메두사 집에 전사는 없다
1. 메두사 이동
메두사는 <도로만 따라서> 최단거리로 공원으로 가고 있다. (최단경로 구해야함 역추적)
이때 최단경로 우선순위는 상하좌우, 가다가 전사 만나면 죽여버림/ 물론 경로 없을수도 있음
2. 메두사 바라보기
바라보는 방향으로 90도 시야각, 다른 전사 뒤에 있는 전사는 돌로 안됨
가려지는 기준
(1) 일직선에 전사
(2) 대각선에 전사
(3) 그밖에 전사 <- 일직선 + 대각선 해야함
그밖 전사는 일직선 범위, 대각선 범위로 칠해버리고 그 사이를 안전 지대로 칠해버리면 된다


상하좌우 우선순위로 가장 많은 전사를 볼 수 있는 거리로 바라본다
한 좌표에 여러 전사가 있으면 모두 돌로 된다. (3번 불가)
돌로 되면 다음 턴에 풀림
3. 전사 이동 -> 메두사를 향해 <거리를 줄일 수 있는 방향으로 2칸 이동> 거리는 멘헤튼거리
이때 첫번째 이동은 상하좌우
두번째 이동은 좌우상하
격자 밖에 못나가고 메두사 시야로는 못움직임
4. 전사 공격 -> 하지만 사라진다

출력해야할것
매 턴마다
1. 해당 턴의 모든 전사들이 이동한 거리 합
2. 해당 턴에 돌이 된 전사 수
3. 해당 턴에 메두사 공격한 전사 수
*/

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <algorithm>
#define STREET 0
#define NOSTREET 1
#define WAR 2
#define MED 3
#define HOUSE 4
#define PARK 5
#define TOP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define RIGHTTOP 4
#define RIGHTDOWN 5
#define LEFTTOP 6
#define LEFTDOWN 7
using namespace std;
using pii = pair<int, int>;

int N, M, sr, sc, er, ec; 

int arr[51][51], visit[51][51], path[51][51];
int dx[8] = {-1, 1, 0, 0, -1, 1, -1, 1}, dy[8] = {0, 0, -1, 1, 1, 1, -1, -1};
int first_prior[4] = {TOP, DOWN, LEFT, RIGHT}, second_prior[4] = {LEFT, RIGHT, TOP, DOWN};
// 항상 보는 기준으로 직진, 왼쪽, 오른쪽
int med_see[4][3] = {
    {TOP, RIGHTTOP, LEFTTOP}, // TOP
    {DOWN, LEFTDOWN, RIGHTDOWN}, // DOWN
    {LEFT, LEFTTOP, LEFTDOWN}, // LEFT
    {RIGHT, RIGHTDOWN, RIGHTTOP}, // RIGHT
};
pii parent[51][51];
vector<int> war_board[51][51], tmp_war_board[51][51];
int area[51][51];  // -1이 메두사 시야 범위, -2가 초기
int war_cnt[4]; 

void search(int x, int y, int mid_dir, int diag_dir, int see){
    if (mid_dir != diag_dir){
        for(int tmp_x = x, tmp_y = y; 0 <= tmp_x && tmp_x < N && 0 <= tmp_y && tmp_y < N; tmp_x += dx[diag_dir], tmp_y += dy[diag_dir]){
            // cout << tmp_x << " " << tmp_y << " " << mid_dir << " " << diag_dir << " " << see << "\n";
            for(int nx = tmp_x, ny = tmp_y; 0 <= nx && nx < N && 0 <= ny && ny < N; nx += dx[mid_dir], ny += dy[mid_dir]){
                if (see == -1) {
                    if (war_board[nx][ny].size() > 0){
                        area[nx][ny] = (tmp_x == x && tmp_y == y ? mid_dir : diag_dir);
                        for(auto &x : war_board[nx][ny]) x = 1; // 돌이 됨
                    } else area[nx][ny] = see;
                } else {
                    if (nx != x || ny != y) {
                        area[nx][ny] = -2;
                        for(auto &x : war_board[nx][ny]) x = 0; // 안전지대
                    }
                }
                
            }
        }
    } else { // 처음에 직진으로만 있는 경우
        for(int nx = x, ny = y; 0 <= nx && nx < N && 0 <= ny && ny < N; nx += dx[mid_dir], ny += dy[mid_dir]){
            if (nx != x || ny != y) {
                area[nx][ny] = -2;
                for(auto &x : war_board[nx][ny]) x = 0; // 안전지대
            }
        }
    }
}

void do_search(int x, int y, int dir){
    int mid = med_see[dir][0], right = med_see[dir][1], left = med_see[dir][2];
    search(x, y, mid, left, -1);
    // cout << "left " << dx[left] << " " << dy[left] << "\n";
    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < N; j++) cout << area[i][j] << " ";
    //     cout << "\n";
    // }
    search(x, y, mid, right, -1);
    // cout << "right " << dx[right] << " " << dy[right] << "\n";
    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < N; j++) cout << area[i][j] << " ";
    //     cout << "\n";
    // }
    // 안전 지대 만들기
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if (area[i][j] == -2) continue;
            if (area[i][j] == mid) search(i, j, mid, mid, -2);
            else if (area[i][j] == left) search(i, j, mid, left, -2);
            else if (area[i][j] == right) search(i, j, mid, right, -2);
        }
    }
    // 돌 된 전사 개수 세기
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) {
            if  (war_board[i][j].size() > 0 && war_board[i][j].front() == 1) war_cnt[dir] += war_board[i][j].size();
        }
    }
    // cout << "final \n";
    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < N; j++) cout << area[i][j] << " ";
    //     cout << "\n";
    // }
    // cout << "\n";
    // cout << "warrior \n";
    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < N; j++) {
    //         int cnt = 0;
    //         for(auto x : war_board[i][j]) if (x == 1) cnt++;
    //         cout << cnt << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";
    
    
    
    // 시작점 -> 현재 시점 + (좌우) 물론 범위 넘어가면 pass
    // 끝점 -> 좌우로 각각 끝까지 갔을 때 만난 부분
    // 범위 -> 첫번째부터 +1씩 늘려가며 왼, 오를 1씩 늘려감
    // 끝나는 부분의 방향으로 더 있다면 확인
    // 직선이 아니면 삼각형임
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M >> sr >> sc >> er >> ec; // m은 전사의 수
    arr[sr][sc] = HOUSE; arr[er][ec] = PARK;
    // 전사 벡터 배열에 넣기
    while (M--){
        int r, c; cin >> r >> c;
        war_board[r][c].push_back(0);
    }
    // 도로 초기화
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cin >> arr[i][j];
    }
    // 메두사 최단경로 구하기
    queue<pii> q;
    visit[sr][sc] = 1;
    q.push({sr, sc});
    bool flag = true;
    while (q.size()){
        auto cur = q.front(); q.pop();
        if (cur.first == er && cur.second == ec) {
            flag = false;
            break;
        }
        for(int d : first_prior){
            int nx = cur.first + dx[d], ny = cur.second + dy[d];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N || arr[nx][ny] != STREET || visit[nx][ny]) continue;
            visit[nx][ny] = 1;
            parent[nx][ny] = cur;
            q.push({nx, ny});
        }
    }
    // 메두사의 최단 경로가 없는 경우
    if (flag) {
        cout << -1;
        return 0;
    }
    // 메두사 최단경로 저장하기
    stack<pii> stk;
    pii tmp_pair = {er, ec};
    do {
        // cout << tmp_pair.first << " " << tmp_pair.second << "\n";
        stk.push(tmp_pair);
        tmp_pair = parent[tmp_pair.first][tmp_pair.second];
    } while (tmp_pair.first != sr || tmp_pair.second != sc);
    // 메두사 이동 시작 (집에서 한칸 이동한거 부터 시작하기 때문에 초기 집 위치는 필요 없음)
    while (stk.size()){
        int war_sum = 0, stone_num = 0, attack_num = 0;
        pii med_cur = stk.top(); stk.pop();
        // 공원 도착
        if (med_cur.first == er && med_cur.second == ec){
            cout << 0;
            break;
        }
        // 지나가다가 전사를 만나면 공격 못하고 사라짐
        if (war_board[med_cur.first][med_cur.second].size() > 0) war_board[med_cur.first][med_cur.second].clear();
        // 2. 메두사 시선
        // 가장 많은 전사를 볼 수 있는 곳으로 바라봄 상하좌우 우선순위 (돌된 애들만 카운트)
        
        int final_dir = 0, final_war_cnt = -1;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++) area[i][j] = -2;
        }
        for(int d = 0; d < 4; d++) {
            do_search(med_cur.first, med_cur.second, d);
            // cout << "\nwarr_cnt\n";
            // cout << d << " " << war_cnt[d] << "\n";
            if (war_cnt[d] > final_war_cnt){
                final_war_cnt = war_cnt[d];
                final_dir = d; // 상하좌우 우선순위
            }
            // 초기화 -> 메두사 영역, 전사 돌 
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++) area[i][j] = -2;
            }
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++) {
                    for(auto &x : war_board[i][j]) x = 0;
                }
            }
        }
        // 여긴 초기화 안함
        // cout << "out!\n";
        // cout << final_dir << " " << final_war_cnt << "\n";
        do_search(med_cur.first, med_cur.second, final_dir);
        
        // 돌이 된 곳은 이동 못함
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++) {
                if (area[i][j] >= 0) area[i][j] = -1;
            }
        }
        // cout << "final \n";
        // for(int i = 0; i < N; i++){
        //     for(int j = 0; j < N; j++) cout << area[i][j] << " ";
        //     cout << "\n";
        // }
        // cout << "\n";
        // 메두사로 이동할 수 있게
        area[med_cur.first][med_cur.second] = -2;
        memset(war_cnt, 0, sizeof(war_cnt));
        
        
        // cout << "stone warrior \n";
        // for(int i = 0; i < N; i++){
        //     for(int j = 0; j < N; j++) {
        //         int cnt = 0;
        //         for(auto x : war_board[i][j]) if (x == 1) cnt++;
        //         cout << cnt << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";

        // 3. 전사 이동
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                // 첫번째 이동, 상하좌우, 시야로는 못감
                // 전사 있고,  돌이 아닌경우
                int war_move_dist[4]; memset(war_move_dist, 0, sizeof(war_move_dist));
                if (war_board[i][j].size() > 0 && war_board[i][j].front() == 0){
                    // cout << war_sum << "\n";
                    // cout << "in\n";
                    // cout << i << " " << j << "\n";
                    int base_dis = abs(med_cur.first - i) + abs(med_cur.second - j), cur_war_num = war_board[i][j].size();
                    for(int d : first_prior){
                        int nx = i + dx[d], ny = j + dy[d];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= N || area[nx][ny] == -1) continue;
                        war_move_dist[d] = base_dis - (abs(med_cur.first - nx) + abs(med_cur.second - ny));
                    }
                    int first_move_dir = 10;
                    // cout << "first_prior\n";
                    for(int d : first_prior){
                        // cout << war_move_dist[d] << " ";
                        if (war_move_dist[d] > 0) first_move_dir = min(first_move_dir, d); // 양수가 가까워지는 방향
                    }
                    // 아무곳도 못가는 경우
                    if (first_move_dir == 10) continue;
                    
                    int tmp_x = i + dx[first_move_dir], tmp_y = j + dy[first_move_dir];
                    // 전사 움직임 현재 전사 개수 만큼 증가
                    war_sum += cur_war_num;

                    // 첫번째 움직임
                    // cout << "first move\n";
                    // cout << first_move_dir << " " << war_move_dist[first_move_dir] << "\n";
                    // cout << tmp_x << " " << tmp_y << "\n";
                    // 근데 메두사를 만났어 ㅋㅋㅋㅋ 그럼 공격하고 죽어야지
                    if (tmp_x == med_cur.first && tmp_y == med_cur.second){
                        attack_num += cur_war_num;
                        war_board[i][j].clear();
                        continue;
                    }


                    // 두번째 움직임 확인
                    memset(war_move_dist, 0, sizeof(war_move_dist));
                    base_dis = abs(med_cur.first - tmp_x) + abs(med_cur.second - tmp_y);
                    for(int d : second_prior){
                        int nx = tmp_x + dx[d], ny = tmp_y + dy[d];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= N || area[nx][ny] == -1 || (nx == i && ny == j)) continue;
                        war_move_dist[d] = base_dis - (abs(med_cur.first - nx) + abs(med_cur.second - ny));
                    }
                    int second_move_dir = 10;
                    // cout << "second_move \n";
                    for(int i = 0; i < 4; i++){
                        // cout << war_move_dist[i] << " ";
                        if (war_move_dist[second_prior[i]] > 0) second_move_dir = min(second_move_dir, i);
                    }
                    // 아무곳도 못가는 경우 -> 첫번째만 이동
                    if (second_move_dir == 10) {
                        for(int d = 0; d < war_board[i][j].size(); d++) tmp_war_board[tmp_x][tmp_y].push_back(0);
                        war_board[i][j].clear();
                        continue;
                    }
                    // 두번째까지 가능
                    second_move_dir = second_prior[second_move_dir];
                    tmp_x += dx[second_move_dir], tmp_y += dy[second_move_dir];
                    for(int d = 0; d < war_board[i][j].size(); d++) tmp_war_board[tmp_x][tmp_y].push_back(0);
                    war_board[i][j].clear();
                    // 전사 움직임 1 증가
                    war_sum += cur_war_num;
                    // cout << "second move\n";
                    // cout << second_move_dir << " " << war_move_dist[second_move_dir] << "\n";
                    // cout << tmp_x << " " << tmp_y << "\n";
                }
            }
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                // 돌 된 친구 개수 세기
                if (war_board[i][j].size() > 0 && war_board[i][j].front() == 1) {
                    stone_num += war_board[i][j].size();
                    for(auto &x : war_board[i][j]) x = 0; // 석화 풀어주기
                } else {
                    // 움직인 애들 반영하기
                    for(int d = 0; d < tmp_war_board[i][j].size(); d++) war_board[i][j].push_back(0);
                }
                tmp_war_board[i][j].clear();
            }
        }

        // 4. 전사 공격
        if (war_board[med_cur.first][med_cur.second].size() > 0){
            attack_num += war_board[med_cur.first][med_cur.second].size();
            war_board[med_cur.first][med_cur.second].clear();
        }
        // cout << "\n";
        // cout << "live warrior \n";
        // for(int i = 0; i < N; i++){
        //     for(int j = 0; j < N; j++) {
        //         int cnt = 0;
        //         for(auto x : war_board[i][j]) if (x == 0) cnt++;
        //         cout << cnt << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";
        cout << war_sum << " " << stone_num << " " << attack_num << "\n";
    }
}
