#include <iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    while (n--){
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        if (x1 == x2 and y1 == y2 and r1 == r2){
            cout << -1 << "\n";
            continue;
        }
        int dst = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        int tmp1 = (r1 + r2) * (r1 + r2);
        int tmp2 = (r1 - r2) * (r1 - r2);
        if (dst == tmp1 or dst == tmp2) cout << 1 << "\n";
        else if (dst < tmp1 and dst > tmp2) cout << 2 << "\n";
        else cout << 0 << "\n";
    }
    return 0;
}