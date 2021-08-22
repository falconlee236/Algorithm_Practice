/*2580*/
/*Cheating*/
#include <iostream>
using namespace std;

int arr[9][9];
bool row[9][10];
bool col[9][10];
bool square[9][10];

void func(int n){
    int x = n / 9;
    int y = n % 9;
    
    if(n == 81){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
        exit(0);
    }
    
    if(!arr[x][y]){
        for(int i = 1; i <= 9; i++){
            if(!row[x][i] && !col[y][i] && !square[(x / 3) * 3 + y / 3][i]){
                row[x][i] = true;
                col[y][i] = true;
                square[(x / 3) * 3 + y / 3][i] = true;
                arr[x][y] = i;
                func(n + 1);
                arr[x][y] = 0;
                square[(x / 3) * 3 + y / 3][i] = false;
                col[y][i] = false;
                row[x][i] = false;
            }
        }
    }
    else func(n + 1);
}

int main() {
	for(int i = 0; i < 9; i++){
	    for(int j = 0; j < 9; j++){
	        int num; scanf("%d", &num);
	        arr[i][j] = num;
	        if(num){
	            row[i][num] = true;
    	        col[j][num] = true;
    	        square[(i / 3) * 3 + (j / 3)][num] = true;
	        }
	    }
	}
	func(0);
	return 0;
}
