/*2447*/
/*Got it!*/
#include <iostream>
using namespace std;
char arr[6561][6561];

void solve(int x, int y, int size){
    if(size == 3){
        for(int i = x; i < x + size; i++){
            for(int j = y; j < y + size; j++){
                if(i == x + 1 && j == y + 1) arr[i][j] = ' ';
                else arr[i][j] = '*';
            }
        }
    }
    else{
        int n = size / 3;
        for(int i = 0; i < 3; i++){
           for(int j = 0; j < 3; j++){
                if(i == 1 && j == 1){
                    int a = x + n * i, b = y + n * j;
                    for(int l = a; l < a + size; l++){
                        for(int m = b; m < b + size; m++){
                            arr[l][m] = ' ';
                        }
                    }
                }
                else solve(x + n * i, y + n * j, n);
            }
        }
    }
}

int main(){
    int n; scanf("%d", &n);
    solve(0, 0, n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}