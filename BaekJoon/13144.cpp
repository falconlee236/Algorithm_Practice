#include <iostream>
using namespace std;
int idx[100001];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    long ans = 0;
    int arr[n]; for(int& x: arr) cin >> x;
    for(long i = 0, j = 0; i < n; i++){
        idx[arr[i]]++;
        while (idx[arr[i]] != 1 && j < n && j < i) {
            idx[arr[j]]--;
            j++;
        }
        ans += i - j + 1LL;
    }
    cout << ans;
}