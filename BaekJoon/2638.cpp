/*2638*/
/*Got it!*/
#include <iostream>
#include <algorithm>
using namespace std;

int cheese[101][101];
int pos[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int n, m, num;

void dfs(bool (*visit)[101], int row, int col, int s){
    visit[row][col] = true;
    cheese[row][col] = s;
    for(int i = 0; i < 4; i++){
        int nrow = row + pos[i][0];
        int ncol = col + pos[i][1];
        if(0 <= nrow && nrow < n && 0 <= ncol && ncol < m){
            if(!visit[nrow][ncol] && cheese[nrow][ncol] != 1){
                dfs(visit, nrow, ncol, s);
            }
        }
    }
}

void dfs_2(bool (*visit)[101], int row, int col){
    visit[row][col] = true;
    int cnt = 0;
    for(int i = 0; i < 4; i++){
        int nrow = row + pos[i][0];
        int ncol = col + pos[i][1];
        if(0 <= nrow && nrow < n && 0 <= ncol && ncol < m){
            if(!visit[nrow][ncol] && cheese[nrow][ncol] == 0) cnt++;
        }
    }
    if(cnt > 1){
        cheese[row][col] = 0;
        num--;
    }

    for(int i = 0; i < 4; i++){
        int nrow = row + pos[i][0];
        int ncol = col + pos[i][1];
        if(0 <= nrow && nrow < n && 0 <= ncol && ncol < m){
            if(!visit[nrow][ncol] && cheese[nrow][ncol] == 1){
                dfs_2(visit, nrow, ncol);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            cin >> cheese[i][j];
            if(cheese[i][j] == 1) num++;
        }
            
    int t = 0;
    while(num > 0){
        bool visit[101][101] = {};
        int state = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(cheese[i][j] == 0 && !visit[i][j]){
                    dfs(visit, i, j, state--);
                }
            }
        }
        
        fill(visit[0], visit[0] + 101 * 101, false);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(cheese[i][j] == 1 && !visit[i][j]){
                    dfs_2(visit, i, j);
                }
            }
        }
        t++;
    }
    cout << t;
    
	return 0;
}