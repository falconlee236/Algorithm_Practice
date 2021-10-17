/*2217*/
/*00:09*/
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = max(ans, arr[n - i] * i);
    cout << ans;
    return 0;
}