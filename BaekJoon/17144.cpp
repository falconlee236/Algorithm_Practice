/*17144*/
/*Got it!*/
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int air[55][55];

int main(){
    int r, c, t; cin >> r >> c >> t;
    int cond = 0;
    for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) cin >> air[i][j];
    for(int i = 0; i < r; i++){
        if(air[i][0] == -1){
            cond = i; 
            break;
        }
    }
    int pos[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    while(t--){
        queue<tuple<int, int, int>> q;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(air[i][j] > 0) q.emplace(i, j, air[i][j]);
            }
        }
        while(!q.empty()){
            int row = get<0>(q.front());
            int col = get<1>(q.front());
            int dust = get<2>(q.front());
            q.pop();
            int cnt = 0;
            for(int i = 0; i < 4; i++){
                int nrow = row + pos[i][0];
                int ncol = col + pos[i][1];
                if(0 <= nrow && nrow < r && 0 <= ncol && ncol < c){
                    if(air[nrow][ncol] != -1){
                        cnt++;
                        air[nrow][ncol] += (dust / 5);
                    }
                }
            }
            air[row][col] -= ((dust / 5) * cnt);
        }

        for(int i = cond - 2; i >= 0; i--) air[i + 1][0] = air[i][0];
        for(int i = cond + 3; i < r; i++) air[i - 1][0] = air[i][0];
        
        for(int i = 1; i < c; i++){
            air[0][i - 1] = air[0][i];
            air[r - 1][i - 1] = air[r - 1][i];
        }
        
        for(int i = 1; i <= cond; i++) air[i - 1][c - 1] = air[i][c - 1];
        for(int i = r - 2; i >= cond + 1; i--) air[i + 1][c - 1] = air[i][c - 1];
        
        for(int i = c - 2; i > 0; i--){
            air[cond][i + 1] = air[cond][i];
            air[cond + 1][i + 1] = air[cond + 1][i];
        }
        air[cond][1] = 0;
        air[cond + 1][1] = 0;
    }
    int res = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            res += air[i][j];
        }
    }
    cout << res + 2;
    return 0;
}