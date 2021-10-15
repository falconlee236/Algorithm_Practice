#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n ; i++) cin >> a[i];
    for(int i = 0; i < n ; i++) cin >> b[i];
    sort(a, a + n);
    sort(b, b + n, greater<int>());
    int res = 0;
    for(int i = 0; i < n; i++) res += a[i] * b[i];
    cout << res;
    return 0;
}