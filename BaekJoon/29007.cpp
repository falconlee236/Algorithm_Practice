#include <iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    char arr[4] = {'A', 'X', 'D', 'W'};
    for(int i = 0; i < n; i++){
        int x, y, base_x, base_y, idx = 0; cin >> x >> y;
        string s;
        if (x > 0 && abs(x) >= abs(y)){
            base_x = max(x, y), base_y = -base_x;
            s += string(y - base_y, 'X');
            idx = base_x * 4;
        } else if (x < 0 && abs(x) >= abs(y)){
            base_x = min(x, y), base_y = -base_x;
            s += string(base_y - y, 'W');
            idx = base_y * 4 - 2;
        } else if (y > 0 && abs(x) <= abs(y)){
            base_y = max(x, y), base_x = base_y - 1; 
            s += string(base_x - x, 'D');
            idx = base_x * 4 + 1;
        } else if (y < 0 && abs(x) <= abs(y)){
            base_y = min(x, y), base_x = base_y;
            s += string(x - base_x, 'A');
            idx = -base_x * 4 - 1;
        }
        for(int j = idx; j >= 0; j--){
            s += string((j + 1) / 2, arr[j % 4]);
        }
        cout << s << "\n";
    }
}