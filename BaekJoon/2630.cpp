/*2630*/
/*Got it!*/
/*09:07*/
#include <iostream>
using namespace std;

int white, blue;
char board[128][128];
void solve(int row, int col, int size){
    char cur = board[row][col];
    bool flag = false;
    if(size == 1){
        if(cur == '0') white++;
        else blue++;
        return;
    }
    
    for(int i = row; i < row + size; i++){
        for(int j = col; j < col + size; j++){
            if(board[i][j] != cur){
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    if(flag){
        int s = size / 2;
        solve(row, col, s);
        solve(row + s, col, s);
        solve(row, col + s, s);
        solve(row + s, col + s, s);
    }
    else{
        if(cur == '0') white++;
        else blue++;
    }
    
}

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    solve(0, 0, n);
    cout << white << "\n" << blue;
    return 0;
}