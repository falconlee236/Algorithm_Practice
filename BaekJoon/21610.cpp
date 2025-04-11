#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int dx[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1}, dy[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int arr[51][51], visit[51][51], delta[51][51];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, T; cin >> N >> T;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++) cin >> arr[i][j];
    }
    /*
    초기 구름은 N 1, N 2, N - 1 1, N - 1 2
    */
   queue<pair<int, int>> q;
   q.push({N, 1}); q.push({N, 2}); q.push({N - 1, 1}); q.push({N - 1, 2}); 
    while(T--){
        int d, s; cin >> d >> s; // 방향, 거리
        while (q.size()){
            auto cur = q.front(); q.pop();
            int nx = cur.first + dx[d] * (s % N), ny = cur.second + dy[d] * (s % N);
            if (nx < 1) nx += N;
            if (ny < 1) ny += N;
            if (nx > N) nx -= N;
            if (ny > N) ny -= N;
            // 구름이 움직임
            visit[nx][ny] = 1;
            // 바구니 물 1 증가
            arr[nx][ny] += 1;
        }
        // 구름이 모두 사라짐
        // 물 복사 버그 시작 - 대상 = 물이 증가한 바구니
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if (visit[i][j] != 1) continue;
                for(int d = 2; d <= 8; d+=2){
                    int nx = i + dx[d], ny = j + dy[d];
                    if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
                    delta[i][j] += (arr[nx][ny] > 0 ? 1 : 0);
                }
            }
        }
        // 물이 2 이상이면 물을 2 줄이고 구름이 생긴다. 구름은 이전에 사라진 곳이 아닐때만 생김
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                arr[i][j] += delta[i][j];
                if (arr[i][j] < 2 || visit[i][j]) continue;
                arr[i][j] -= 2;
                q.push({i, j});
            }
        }
        memset(visit, 0, sizeof(visit));
        memset(delta, 0, sizeof(delta));
    }
    int ans = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++) ans += arr[i][j];
    }
    cout << ans;
}