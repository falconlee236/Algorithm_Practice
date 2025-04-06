#include <iostream>
#include <algorithm>
using namespace std;
int arr[500][500];
int ans, n;
// 동서남북 = 0123
void cal(int x, int y, int pos){
    int point[10][3]; // 1, 1, 2, 2, 7, 7, 10, 10, 5
    int one = arr[x][y] * 0.01, two = arr[x][y] * 0.02, five = arr[x][y] * 0.05, seven = arr[x][y] * 0.07, ten = arr[x][y] * 0.1;
    point[0][2] = one, point[1][2] = one;
    point[2][2] = two, point[3][2] = two;
    point[4][2] = seven, point[5][2] = seven;
    point[6][2] = ten, point[7][2] = ten;
    point[8][2] = five, point[9][2] = arr[x][y] - ((one + two + seven + ten) * 2) - five;
    arr[x][y] = 0;
    int dx[12] = {-2, -1, -1, -1, 0, 0, 0, 0, 1, 1, 1, 2}, dy[12] = {0, -1, 0, 1, -2, -1, 1, 2, -1, 0, 1, 0};
    if (pos == 0){
        int nd[10] = {1, 8, 0, 11, 2, 9, 3, 10, 7, 6};
        for(int i = 0; i < 10; i++) point[i][0] = x + dx[nd[i]], point[i][1] = y + dy[nd[i]];
    } else if (pos == 1){
        int nd[10] = {3, 10, 0, 11, 2, 9, 1, 8, 4, 5};
        for(int i = 0; i < 10; i++) point[i][0] = x + dx[nd[i]], point[i][1] = y + dy[nd[i]];
    } else if (pos == 2){
        int nd[10] = {3, 1, 4, 7, 5, 6, 8, 10, 11, 9};
        for(int i = 0; i < 10; i++) point[i][0] = x + dx[nd[i]], point[i][1] = y + dy[nd[i]];
    } else {
        int nd[10] = {10, 8, 4, 7, 5, 6, 3, 1, 0, 2};
        for(int i = 0; i < 10; i++) point[i][0] = x + dx[nd[i]], point[i][1] = y + dy[nd[i]];
    }
    for(int i = 0; i < 10; i++){
        int cx = point[i][0], cy = point[i][1], cost = point[i][2];
        if (cx < 0 || cx >= n || cy < 0 || cy >= n) {
            ans += cost;
            continue;
        }
        arr[cx][cy] += cost;
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> arr[i][j];
    }
    int x = n / 2, y = n / 2;
    for(int cnt = 1;; cnt++){
        if (cnt % 2 == 1){
            for(int i = y - 1; i >= max(y - cnt, 0); i--) cal(x, i, 1);
            y = max(y - cnt, 0);
            if (x == 0 && y == 0) break;
            for(int i = x + 1; i <= min(x + cnt, n - 1); i++) cal(i, y, 2);
            x = min(x + cnt, n - 1);
            if (x == 0 && y == 0) break;
        } else {
            for(int i = y + 1; i <= min(y + cnt, n - 1); i++) cal(x, i, 0);
            y = min(y + cnt, n - 1);
            if (x == 0 && y == 0) break;
            for(int i = x - 1; i >= max(x - cnt, 0); i--) cal(i, y, 3);            
            x = max(x - cnt, 0);
            if (x == 0 && y == 0) break;
        }
    }
    cout << ans;
}