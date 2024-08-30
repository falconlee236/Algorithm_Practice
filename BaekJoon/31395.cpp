#include <iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, cnt = 1; cin >> n;
    int arr[n]; for(int &x : arr) cin >> x;
    long long ans = 1;
    for(int i = n - 1; i > 0; i--){
        if (arr[i] < arr[i - 1]) cnt = 1;
        else cnt++;
        ans += cnt;
    }
    cout << ans;
}