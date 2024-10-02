#include <iostream>
using namespace std;
int n;
void solve(int num, int cnt){
    if (cnt == n - 1){
        cout << num << "\n";
        return;
    }
    for(int i = 0; i < 10; i++){
        int tmp = num * 10 + i, flag = 0;
        for(int j = 2; j * j <= tmp; j++){
            if (tmp % j == 0){
                flag = 1;
                break;
            }
        }
        if (!flag) solve(num * 10 + i, cnt + 1);
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    solve(2, 0), solve(3, 0), solve(5, 0), solve(7, 0);
}