#include <iostream>
#include <algorithm>
using namespace std;
int lst[1001];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    int num, ans = 0, idx = 0; cin >> num;
    int arr[num]; for(auto &x : arr) cin >> x;
    sort(arr, arr + num);
    for(int i = 0; i < num; i++){
        if (lst[idx] >= arr[i]) continue;
        lst[idx] = arr[i];
        idx = (idx + 1) % m;
        ans++;
    }
    cout << (ans <= n * m ? ans : n * m);
}