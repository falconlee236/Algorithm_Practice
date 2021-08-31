#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int lab[10][10];
int n, m, ans;

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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    vector<pair<int, int>> v;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> lab[i][j];
            if(lab[i][j] == 0) v.push_back({i, j});
        }
    }
    
    int cnt = 0;
    int len = v.size();
    for(int i = 0; i < len - 2; i++){
        lab[v[i].first][v[i].second] = 1;
        for(int j = i + 1; j < len - 1; j++){
            lab[v[j].first][v[j].second] = 1;
            for(int k = j + 1; k < len; k++){
                lab[v[k].first][v[k].second] = 1;
                bfs();
                lab[v[k].first][v[k].second] = 0;
            }
            lab[v[j].first][v[j].second] = 0;
        }
        lab[v[i].first][v[i].second] = 0;
    }
    
    cout << ans;
    return 0;
}