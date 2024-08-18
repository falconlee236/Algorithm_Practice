#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        ll n; cin >> n;
        ll floor = log2(n) + 1ll;
        ll cnt = pow(2, floor - 1);
        ll room = n - cnt + 1;
        while (floor){
            string floor_str = to_string(floor), room_str = to_string(room);
            cout << floor_str;
            for(int i = 0; i < 18 - room_str.length(); i++) cout << "0";
            cout << room_str << "\n";
            floor--;
            room = (room + 1) / 2;
        }
    }
}