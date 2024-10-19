#include <iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        int arr[n][m], ans = 0;
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> arr[i][j];
        for(int j = 0; j < m; j++){
            for (int i = n - 1, cnt = n - 1; i >= 0; i--){
                if (arr[i][j]) ans += cnt - i, cnt--;
            }
        }
        cout << ans << "\n";
    }
}