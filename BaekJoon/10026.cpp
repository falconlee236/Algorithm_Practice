/*10026*/
/*Got it!*/
#include <iostream>
#include <algorithm>
using namespace std;

int n; 
char arr[110][110];
char new_arr[110][110];
bool visit[110][110];
int pos[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void dfs(int row, int col, char color){
    visit[row][col] = true;
    for(int i = 0; i < 4; i++){
        int nrow = row + pos[i][0], ncol = col + pos[i][1];
        if(0 <= nrow && nrow < n && 0 <= ncol && ncol < n){
            if(arr[nrow][ncol] == color && !visit[nrow][ncol]) dfs(nrow, ncol, color);
        }
    }
}

void dfs_2(int row, int col, char color){
    visit[row][col] = true;
    for(int i = 0; i < 4; i++){
        int nrow = row + pos[i][0], ncol = col + pos[i][1];
        if(0 <= nrow && nrow < n && 0 <= ncol && ncol < n){
            if(new_arr[nrow][ncol] == color && !visit[nrow][ncol]) dfs_2(nrow, ncol, color);
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char ch; cin >> ch;
            arr[i][j] = ch;
            new_arr[i][j] = ch;
            if(ch == 'G') new_arr[i][j] = 'R';
        }
    }
    int a = 0, b = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visit[i][j]){
                dfs(i, j, arr[i][j]);
                a++;
            }
        }
    }
    
    fill(visit[0], visit[0] + 110 * 110, false);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visit[i][j]){
                dfs_2(i, j, new_arr[i][j]);
                b++;
            }
        }
    }
    cout << a << " " << b;
    return 0;
}