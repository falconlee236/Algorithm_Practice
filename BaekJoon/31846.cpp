#include <iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, q, l, r; cin >> n;
    char arr[n + 1];
    for(int i = 1; i <= n; i++) cin >> arr[i];
    cin >> q;
    while (q--){
        int ans = 0; cin >> l >> r;
        for(int i = l; i < r; i++){
            int tmp = 0, left = i, right = i + 1;
            while (left >= l && right <= r) tmp += arr[left--] == arr[right++];
            ans = max(ans, tmp);
        }      
        cout << ans << "\n";
    }
}