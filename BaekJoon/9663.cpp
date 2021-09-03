/*9663*/
/*Cheating*/
#include <iostream>
#include <cmath>
using namespace std;

int n, ans, col[15];

bool check(int line){
    for(int i = 0; i < line; i++){
        if(col[i] == col[line] || abs(col[i] - col[line]) == line - i) return false;
    }
    return true;
}

void func(int line){
    if(line == n){
        ans++;
        return;
    }
    for(int i = 0; i < n; i++){
        col[line] = i;
        if(check(line)) func(line + 1);
    }
}


int main(){
    cin >> n;
    func(0);
    cout << ans;
    return 0;
}