/*2146*/
/*Cheating*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    int island[102][102];
    int group[102][102];
    int dist[102][102];
    fill(island[0], island[0] + 102 * 102, -1);
    fill(group[0], group[0] + 102 * 102, -1);
    fill(dist[0], dist[0] + 102 * 102, -1);
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) scanf("%d", &island[i][j]);
    }
    
    int pos[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    queue<pair<int, int>> q;
    int num = 2;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(island[i][j] == 1){
                q.push(make_pair(i, j));
                island[i][j] = num;
                while(!q.empty()){
                    pair<int, int> cur = q.front();
                    q.pop();
                    for(int i = 0; i < 4; i++){
                        int nx = cur.first + pos[i][0];
                        int ny = cur.second + pos[i][1];
                        if(island[nx][ny] == 1){
                            island[nx][ny] = num;
                            q.push(make_pair(nx, ny));
                        }
                    }
                }
                num++;
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(island[i][j] > 1){
                group[i][j] = island[i][j];
                dist[i][j] = 0;
                q.push(make_pair(i, j));
            }
        }
    }
    
    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = cur.first + pos[i][0];
            int ny = cur.second + pos[i][1];
            if(island[nx][ny] > -1){
                if(dist[nx][ny] == -1){
                    q.push(make_pair(nx, ny));
                    dist[nx][ny] = dist[cur.first][cur.second] + 1;
                    group[nx][ny] = group[cur.first][cur.second];
                }
            }
        }
    }
    
    int ans = -1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 0; k < 4; k++){
                int nx = i + pos[k][0];
                int ny = j + pos[k][1];
                if(island[nx][ny] > -1){
                    if(group[nx][ny] != group[i][j]){
                        if(ans == -1 || ans > dist[nx][ny] + dist[i][j]) ans = dist[nx][ny] + dist[i][j];
                    }
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}