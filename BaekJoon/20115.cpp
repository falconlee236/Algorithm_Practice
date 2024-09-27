#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    double arr[n]; for(double &x: arr) cin >> x;
    sort(arr, arr + n);
    double res = arr[n - 1];
    for(int i = 0; i < n - 1; i++) res += arr[i] / 2;
    cout << res;
}