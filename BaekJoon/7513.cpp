#include <iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T, n, m, k, idx; cin >> T;
    for(int t = 1; t <= T; t++){
        cout << "Scenario #" << t << ":\n";
        cin >> n;
        string strs[n]; for(auto &x : strs) cin >> x;
        cin >> m;
        while (m--){
            cin >> k; 
            while (k--){
                cin >> idx;
                cout << strs[idx];
            }
            cout << "\n";
        }
        cout << "\n";
    }
}