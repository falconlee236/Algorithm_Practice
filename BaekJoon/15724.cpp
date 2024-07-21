#include <iostream>
using namespace std;
int a[1030][1030], pre[1030][1030];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k, x1, y1, x2, y2; cin >> n >> m;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) cin >> a[i][j];
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) pre[i][j] = a[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
    cin >> k;
    while (k--){
        cin >> x1 >> y1 >> x2 >> y2;
        cout << pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1] << "\n";
    }
}