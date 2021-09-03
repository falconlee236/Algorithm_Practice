#include <iostream>
#include <algorithm>
using namespace std;

char board[25][25];
int h, w; 

int func(){
    int row = -1, col = -1;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            if(board[i][j] == '.'){
                row = i;
                col = j; 
                break;
            }
        }
        if(row != -1) break;
    }

    if(row == -1) return 1;
    int res = 0;
    if(board[row + 1][col] == '.' && board[row][col + 1] == '.'){
        board[row][col] = board[row + 1][col] = board[row][col + 1] = '#';
        res += func();
        board[row][col] = board[row + 1][col] = board[row][col + 1] = '.';
    }
    
    if(board[row + 1][col] == '.' && board[row + 1][col + 1] == '.'){
        board[row][col] = board[row + 1][col] = board[row + 1][col + 1] = '#';
        res += func();
        board[row][col] = board[row + 1][col] = board[row + 1][col + 1] = '.';
    }
        
    if(board[row + 1][col + 1] == '.' && board[row][col + 1] == '.'){
        board[row][col] = board[row + 1][col + 1] = board[row][col + 1] = '#';
        res += func();
        board[row][col] = board[row + 1][col + 1] = board[row][col + 1] = '.';
    }
    
    if(board[row + 1][col] == '.' && board[row + 1][col - 1] == '.'){
        board[row][col] = board[row + 1][col] = board[row + 1][col - 1] = '#';
        res += func();
        board[row][col] = board[row + 1][col] = board[row + 1][col - 1] = '.';
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        fill(board[0], board[0] + 25 * 25, '#');
        cin >> h >> w;
        int count = 0;
        for(int i = 1; i <= h; i++){
            for(int j = 1; j <= w; j++){
                cin >> board[i][j];
                if(board[i][j] == '.') count++;
            }
        }
        if(count % 3 != 0) cout << 0 << "\n";
        else{
            cout << func() << "\n";
        }

    }
    return 0;
}