#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int lab[10][10];
int n, m, ans;
vector<pair<int, int>> v;

void bfs(){
    int arr[10][10];
    queue<pair<int, int>> q;
    bool visit[10][10] = {};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            arr[i][j] = lab[i][j];
            if(arr[i][j] == 2){
                q.emplace(i, j);
                visit[i][j] = true;
            }
        }
    }
    
    int pos[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + pos[i][0], ny = y + pos[i][1];
            if(0 <= nx && nx < n && 0 <= ny && ny < m){
                if(!arr[nx][ny] && !visit[nx][ny]){
                    visit[nx][ny] = true;
                    arr[nx][ny] = 2;
                    q.emplace(nx, ny);
                }
            }
        }
    }
 
    int res = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 0) res++;
        }
    }
    ans = max(res, ans);
}

void wall(int pos, int cnt){
    if(cnt == 3){
        bfs();
        return;
    }
    for(int i = pos; i < v.size(); i++){
        lab[v[i].first][v[i].second] = 1;
        wall(i + 1, cnt + 1);
        lab[v[i].first][v[i].second] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> lab[i][j];
            if(lab[i][j] == 0) v.push_back({i, j});
        }
    }
    wall(0, 0);
    cout << ans;
    return 0;
}