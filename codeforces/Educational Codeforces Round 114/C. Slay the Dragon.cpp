#include <iostream>
#include <algorithm>
using namespace std;

typedef long long li;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    li arr[200000], sum = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr, arr + n);
    int m; cin >> m;
    while(m--){
        li ans = 2e18;
        li x, y; cin >> x >> y;
        int idx = lower_bound(arr, arr + n, x) - arr;
        if(idx > 0) ans = min(ans, x - arr[idx - 1] + max(0LL, y - (sum - arr[idx - 1])));
        if(idx < n) ans = min(ans, max(0LL, y - (sum - arr[idx])));
        cout << ans << "\n";
    }
    
}