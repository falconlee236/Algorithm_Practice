#include <iostream>
using namespace std;
int arr[50001];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, num, ans = 1; cin >> n;
    for(int i = 0; i < n; i++){ cin >> num; arr[num]++; }
    for(int i = 1; i <= 50000; i++) ans = max(arr[i], ans);
    cout << ans;
}