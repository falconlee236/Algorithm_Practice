#include <iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    int arr[n]; for(auto &x : arr) cin >> x;
    long long res = 0;
    for(int i = 0; i < m; i++) res += arr[i];
    for (long long i = 1, tmp = res; i < n - m; i++) tmp -= arr[i - 1], tmp += arr[i + m - 1], res = max(res, tmp);
    cout << res;
}