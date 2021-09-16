/*1103*/
/*Cheating*/
#include <iostream>
#include <algorithm>
using namespace std;

int pos[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
char board[50][50];
int dp[50][50];
bool visit[50][50];
int n, m;

int dfs(int r, int c){
    if(0 > r || r >= n || 0 > c || c >= m || board[r][c] == 'H') return 0;
    if(visit[r][c]){
        cout << -1;
        exit(0);
    }
    int& ret = dp[r][c];
    if(ret != 0) return ret;
    
    int size = board[r][c] - '0';
    visit[r][c] = true;
    for(int i = 0; i < 4; i++){
        int nr = r + pos[i][0] * size, nc = c + pos[i][1] * size;
        ret = max(ret, dfs(nr, nc) + 1);
    }
    visit[r][c] = false;
    return ret;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> board[i][j];
    }
    cout << dfs(0, 0) << endl;
    return 0;
}