#include <iostream>
using namespace std;
int main(){
    int n, res = 0; cin >> n;
    res += (2 * n + 1) * (2 * n + 1);
    for(int a = -n; a <= n; a++){
        for(int b = -n; b <= n && a != 0; b++) res += (1 - (a + b) >= -n && 1 - (a + b) <= n);
    }
    cout << res;
}