#include <iostream>
using namespace std;
using ll = long long;
ll arr[200010]; 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, q, move = 0; cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> arr[i];
    while(q--){
        int t, i, x, s; cin >> t;
        if (t == 1){
            cin >> i >> x;
            arr[(move + i - 1) % n] += x;
        } else {
            cin >> s;
            move = ((t == 2 ? n - s : s) + move) % n;
        }
    }
    for(int i = 0; i < n; i++) cout << arr[(move + i) % n] << " ";
}