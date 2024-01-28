#include <iostream>
using namespace std;

int a[310][310];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int h, w, x, y; cin >> h >> w >> x >> y;
    for(int i = 0; i < h + x; i++){
        for(int j = 0; j < w + y; j++){
            int num; cin >> num;
            if (i < h && j < w) a[i][j] = num;
        }
    }
    for(int i = x; i < h; i++){
        for(int j = y; j < w; j++){
            a[i][j] -= a[i - x][j - y];
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++) cout << a[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
