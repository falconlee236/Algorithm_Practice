#include <iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    for(int t = 1; t <= T; t++){
        int ans = 0;
        for(int i = 0; i < 10; i++){
            int num; cin >> num;
            ans += (num & 1 ? num : 0);
        }
        cout << "#" << t << " " << ans << "\n";
    }
}