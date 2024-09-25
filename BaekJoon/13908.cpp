#include <iostream>
using namespace std;
int ans, n, m;
int a[10], b[10];
void solve(int num){
    if (num == n){
        int tmp = m;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) {
                if (b[i] == a[j]){
                    tmp--;
                    break;
                }
            }
        }
        if (tmp == 0) ans++;
        return;
    }
    for(int i = 0; i < 10; i++){
        a[num] = i;
        solve(num + 1);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) cin >> b[i];
    solve(0);
    cout << ans;
}