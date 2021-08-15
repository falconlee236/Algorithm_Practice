/*2448*/
/*Got it!*/
#include <iostream>
#include <algorithm>
using namespace std;
#define ROWMAX 6144
#define COLMAX 3072
char arr[COLMAX][ROWMAX];

void solve(int x, int y, int size){
    if(size == 3){
        arr[x][y] = '*';
        arr[x + 1][y - 1] = '*';
        arr[x + 1][y + 1] = '*';
        for(int i = y - 2; i <= y + 2; i++) arr[x + 2][i] = '*';
    }
    else{
        int n = size / 2;
        solve(x, y, n);
        solve(x + n, y - n, n);
        solve(x + n, y + n, n);
    }
}

int main(){
    int n; scanf("%d", &n);
    fill(arr[0], arr[0] + ROWMAX * COLMAX, ' ');
    solve(0, n - 1, n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2 * n - 1; j++){
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}