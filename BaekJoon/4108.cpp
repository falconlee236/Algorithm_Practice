#include <iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    while(1){
        int n, m; cin >> n >> m;
        if (n == 0 && m == 0) break;
        char arr[n][m];
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> arr[i][j];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int tmp = 0;
                if (arr[i][j] != '.') {
                    cout << '*';
                    continue;
                }
                for(int k = 0; k < 8; k++){
                    int nx = i + dx[k], ny = j + dy[k];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny] != '*') continue;
                    tmp++;
                }
                cout << tmp;
            }
            cout << "\n";
        }
    }
}