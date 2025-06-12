// https://www.acmicpc.net/problem/11663
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    int point[n]; for(int& x : point) cin >> x;
    sort(point, point + n);
    while (m--){
        int x, y; cin >> x >> y;
        int front = lower_bound(point, point + n, x) - point, back = upper_bound(point, point + n, y) - point;
        cout << back - front << "\n";
    }
}