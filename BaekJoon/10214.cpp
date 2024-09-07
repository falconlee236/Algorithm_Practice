#include <iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int sa = 0, sb = 0, a, b;
        for(int i = 0; i < 9; i++){
            cin >> a >> b;
            sa += a;
            sb += b;
        }
        cout << (sa > sb ? "Yonsei" : (sa == sb ? "Draw" : "Korea")) << "\n";
    }
}