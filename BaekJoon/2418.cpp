#include <iostream>
using namespace std;
using ll = long long;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
ll dp[201][201][101];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int h, w, l; cin >> h >> w >> l;
    ll ans = 0;
    char arr[h][w], str[l];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++) cin >> arr[i][j];
    }
    for(int i = 0; i < l; i++) cin >> str[i];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++) {
            if (str[0] == arr[i][j]) dp[i][j][0] = 1;
        }
    }
    for(int c = 1; c < l; c++){
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++) {
                if (arr[i][j] != str[c]) continue;
                for(int k = 0; k < 8; k++){
                    int nx = i + dx[k], ny = j + dy[k];
                    if (nx < 0 || nx > h || ny < 0 || ny > w) continue;
                    if (arr[nx][ny] == str[c - 1]) dp[i][j][c] += dp[nx][ny][c - 1];
                }
            }
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++) ans += dp[i][j][l - 1];
    }
    cout << ans;
}