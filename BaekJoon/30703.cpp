#include <iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int a[n], b[n], c[n];
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;
    for(int &x : c) cin >> x;
    for(int i = 0; i < n; i++){
        if (abs(a[i] - b[i]) % c[i] != 0){
            cout << -1;
            return 0;
        }
    }
    int ans = abs(a[0] - b[0]) / c[0];
    for(int i = 1; i < n; i++){
        if ((abs(a[i - 1] - b[i - 1]) / c[i - 1]) % 2 != (abs(a[i] - b[i]) / c[i]) % 2){
            cout << -1;
            return 0;
        }
        ans = max(ans, abs(a[i] - b[i]) / c[i]);
    }
    cout << ans;
}