#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n; cin >> n;
    long long arr[n]; for(auto &x : arr) cin >> x;
    sort(arr, arr + n);
    cout << arr[0] * arr[n - 1];
}