/*1987*/
/*Got it!*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int r, c;
char arr[20][20];
bool visit[26];
int ans = 0;
int pos[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void dfs(int x, int y, int cnt){
    char ch = arr[x][y];
    visit[ch - 'A'] = true;
    for(int i = 0; i < 4; i++){
        int nx = x + pos[i][0];
        int ny = y + pos[i][1];
        if(0 <= nx && nx < r && 0 <= ny && ny < c){
            char nch = arr[nx][ny];
            if(!visit[nch - 'A']) dfs(nx, ny, cnt + 1);
        }
    }
    visit[ch - 'A'] = false;
    ans = max(ans, cnt);
    return;
}


int main(){
    cin >> r >> c;
    getchar();
    for(int i = 0; i < r; i++){
        string str; getline(cin, str);
        for(int j = 0; j < c; j++) arr[i][j] = str[j];
    }
    dfs(0, 0, 1);
    printf("%d", ans);
    return 0;
}