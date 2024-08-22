#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, k, ans = 0, cnt = 0; cin >> n >> k;
    int arr[n]; for(int& x : arr) cin >> x;
    for(int i = 1; i < n; i++){
        if (arr[i] > arr[0]){
            ans += arr[i] - arr[0];
            cnt++;
        }
    }
    cout << ans << " " << cnt;
}