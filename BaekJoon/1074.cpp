/*1074*/
/*Got it!*/
/*36:44*/
#include <iostream>
#include <cmath>
using namespace std;

int n, r, c, ans;
void func(int row, int col, int size){
    if(size == 1){
        if(r == row && c == col){
            cout << ans;
            exit(0);
        }
        ans++;
        return;
    }
    int s = size / 2;
    
    if(row > r || r >= row + size || col > c || c >= col + size){
        ans += size * size;
        return;
    }
    func(row, col, s);
    func(row, col + s, s);
    func(row + s, col, s);
    func(row + s, col + s, s);
}


int main(){
    cin >> n >> r >> c;
    func(0, 0, pow(2, n));
    return 0;
}