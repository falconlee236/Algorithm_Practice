/*7576*/
/*Got it!*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    queue<pair<int, int>> q;
    int m, n; scanf("%d %d", &m, &n);
    int box[1002][1002];
    fill(box[0], box[0] + 1002 * 1002, -1);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) scanf("%d", &box[i][j]);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(box[i][j] == 1){
                q.push(make_pair(i, j));
                cnt++;
            }
        }
    }
    if(cnt == n * m){
        printf("0");
        return 0;
    }
    int res = 0;
    int pos[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    while(!q.empty()){
        int size = q.size();
        while(size--){
            pair<int, int> cur = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int nx = cur.first + pos[i][0];
                int ny = cur.second + pos[i][1];
                if(box[nx][ny] == 0){
                    q.push(make_pair(nx, ny));
                    box[nx][ny] = 1;
                } 
            }
        }
        res++;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!box[i][j]){
                printf("-1");
                return 0;
            }
        }
    }
    printf("%d", res - 1);
    return 0;
}