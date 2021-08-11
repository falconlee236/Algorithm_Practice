/*4963*/
/*Got it!*/
#include <iostream>
#include <cstring>
using namespace std;

int island[51][51];
int visited[51][51];
int w, h;
int pos[8][2] = {
    {-1, 0}, 
    {-1, 1},
    {0, 1},
    {1, 1},
    {1, 0},
    {1, -1},
    {0, -1},
    {-1, -1},
};


void dfs(int x, int y){
    visited[x][y] = 1;
    for(int i = 0; i < 8; i++){
        int x_pos = x + pos[i][0];
        int y_pos = y + pos[i][1];
        if((x_pos < 0 && x_pos >= h) || (y_pos < 0 && y_pos >= w)) continue;
        if(!visited[x_pos][y_pos] && island[x_pos][y_pos]) dfs(x_pos, y_pos);
    }
}

int main(){
    while(1){
        scanf("%d %d", &w, &h);
        if(!w && !h) break;
        for(int i = 0; i < 50; i++){
            memset(island[i], 0, sizeof(island[i]));
            memset(visited[i], 0, sizeof(visited[i]));
        }
        
        int res = 0;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++) scanf("%d", &island[i][j]);
        }
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(!visited[i][j] && island[i][j]){
                    dfs(i, j);
                    res++;
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}