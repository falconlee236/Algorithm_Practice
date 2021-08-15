/*1992*/
/*Got it*/
#include <iostream>
#include <string>
#include <queue>
using namespace std;

char pict[70][70];
queue<char> q;

bool check(int x, int y, int size){
    char num = pict[x][y];
    for(int i = x; i < x + size; i++){
        for(int j = y; j < y + size; j++){
            if(num != pict[i][j]) return false;
        }
    }
    return true;
}

void divide(int x, int y, int size){
    char res = pict[x][y];
    if(check(x, y, size)) q.push(res);
    else{
        int n = size / 2;
        q.push('(');
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                divide(x + i * n, y + j * n, n);
            }
        }
        q.push(')');
    }
}

int main(){
    int n; scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++){
        string str; getline(cin, str);
        for(int j = 0; str[j] != '\0'; j++) pict[i][j] = str[j];
    }
    divide(0, 0, n);
    while(!q.empty()){
        printf("%c", q.front());
        q.pop();
    }
    return 0;
}