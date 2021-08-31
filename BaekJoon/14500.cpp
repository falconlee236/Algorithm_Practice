/*14500*/
/*Cheating*/
#include <iostream>
#include <algorithm>
using namespace std;

int p[501][501];
bool visit[501][501];
int pos[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int n, m, ans; 

void dfs(int x, int y, int sum, int cnt){
    if(cnt == 4){
        ans = max(ans, sum);
        return;
    }
    for(int i = 0; i < 4; i++){
        int nx = x + pos[i][0], ny = y + pos[i][1];
        if(0 <= nx && nx < n && 0 <= ny && ny < m){
            if(!visit[nx][ny]){
                visit[nx][ny] = true;
                dfs(nx, ny, sum + p[nx][ny], cnt + 1);
                visit[nx][ny] = false;
            }
        }
    }
}

void remain(int row, int col){
    if(row + 1 < n && col > 0 && col + 1 < m)
        ans = max(ans, p[row][col - 1] + p[row][col] + p[row][col + 1] + p[row + 1][col]);
    if(row > 0 && col > 0 && col + 1 < m)
        ans = max(ans, p[row][col - 1] + p[row][col] + p[row][col + 1] + p[row - 1][col]);
    if(col > 0 && row > 0 && row + 1 < n)
        ans = max(ans, p[row][col - 1] + p[row][col] + p[row - 1][col] + p[row + 1][col]);
    if(col + 1 < m && row > 0 && row + 1 < n)
        ans = max(ans, p[row][col + 1] + p[row][col] + p[row - 1][col] + p[row + 1][col]);
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> p[i][j];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            visit[i][j] = true;
            dfs(i, j, p[i][j], 1);
            visit[i][j] = false;
            remain(i, j);
        }
    }
    cout << ans;
	return 0;
}
