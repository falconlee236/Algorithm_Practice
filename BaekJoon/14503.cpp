#include <iostream>
#include <cstring>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m, r, c, d; cin >> n >> m >> r >> c >> d;
    int arr[n + 2][m + 2], ans = 0;
    r++, c++;
    memset(arr, 1, sizeof(arr));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) cin >> arr[i][j];
    }
    while (1){
        if (arr[r][c] == 0) arr[r][c] = 2, ans++;
        int cnt = 0;
        for(int i = 0; i < 4; i++){
           if (arr[r + dx[i]][c + dy[i]] == 0) cnt++; 
        }
        if (cnt == 0){
            if (arr[r + dx[(d + 2) % 4]][c + dy[(d + 2) % 4]] == 1) break;
            r += dx[(d + 2) % 4], c += dy[(d + 2) % 4];
        } else {
            d = (d == 0 ? 3 : d - 1);
            if (arr[r + dx[d]][c + dy[d]] != 0) continue;
            r += dx[d], c += dy[d];
        }
    }
    cout << ans;
}