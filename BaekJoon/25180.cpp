#include <iostream>
using namespace std;
int main(void){
    int n; cin >> n;
    int ans = (n - 1) / 9 + 1;
    if (n & 1 && ans % 2 == 0) ans++;
    cout << ans;
}