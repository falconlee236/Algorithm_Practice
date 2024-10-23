#include <iostream>
using namespace std;
int arr[10], ans[10], res = 0;
void solve(int idx, int cnt){
    if (idx == 10){
        if (cnt >= 5) res++;
        return;
    }
    for(int i = 1; i <= 5; i++){
        ans[idx] = i;
        if (idx > 1 && ans[idx - 2] == ans[idx - 1] && ans[idx - 1] == ans[idx]) continue;
        solve(idx + 1, cnt + (arr[idx] == ans[idx]));
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    for(int i = 0; i < 10; i++) cin >> arr[i];
    solve(0, 0);
    cout << res;
}