/*1780*/
/*Cheating*/
#include <iostream>
using namespace std;

//3**7 = 2187
int paper[2190][2190];
int a = 0, b = 0, c = 0;

void divide(int x, int y, int size){
    int num = paper[x][y];
    bool flag = false;
    for(int i = x; i < x + size; i++){
        for(int j = y; j < y + size; j++){
            if(num != paper[i][j]){
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    
    if(flag){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                divide(x + i * size / 3, y + j * size / 3, size / 3);
            }
        }
    }
    else{
        if(num == -1) a++;
        else if(num == 0) b++;
        else c++;
    }
}

int main(){
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) scanf("%d", &paper[i][j]);
    }
    divide(0, 0, n);
    printf("%d\n%d\n%d", a, b, c);
    return 0;
}