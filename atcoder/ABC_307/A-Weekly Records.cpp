#include <iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int res = 0;
    for(int i = 1; i <= n * 7; i++){
        int num; cin >> num;
        res += num;
        if (i % 7 == 0){
            cout << res << " ";
            res = 0;
        }
    }
}