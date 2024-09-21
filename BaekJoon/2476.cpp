#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int a, b, c, n, ans = 0; cin >> n;
    while (n--){
        cin >> a >> b >> c;
        if (a == b && b == c) ans = max(ans, 10000 + a * 1000);
        else if (a == b) ans = max(ans, 1000 + a * 100);
        else if (b == c) ans = max(ans, 1000 + b * 100);
        else if (a == c) ans = max(ans, 1000 + c * 100);
        else ans = max(ans, max({a, b, c}) * 100);
    }
    cout << ans;
}