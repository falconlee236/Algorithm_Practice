#include <iostream>
using namespace std;
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    while (true){
        int a, b, d, mn_x = 50000, mn_y = 50000; cin >> a >> b >> d;
        if (a == 0 && b == 0 && d == 0) break;
        for(int i = -50000; i <= 50000; i++){
            if ((d - a * i) % b == 0) {
                int x = abs(i), y = abs((d - a * i) / b);
                if (x + y < mn_x + mn_y || (x + y == mn_x + mn_y && a * x + b * y < a * mn_x + b * mn_y)){
                    mn_x = x;
                    mn_y = y;
                }
            }
        }
        cout << mn_x << " " << mn_y << "\n";
    }
}