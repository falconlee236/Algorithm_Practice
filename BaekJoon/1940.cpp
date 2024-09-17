#include <iostream>
using namespace std;
int arr[100001];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m, num, ans = 0; cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> num; arr[num]++;
    }
    for(int i = 1; i <= 100000 && m - i >= 0 && m - i <= 100000; i++){
        if (arr[i] && arr[m - i] && i != m - i){
            int cnt = min(arr[i], arr[m - i]);
            arr[i] -= cnt;
            arr[m - i] -= cnt;
            ans += cnt;
        }
    }
    cout << ans;
}