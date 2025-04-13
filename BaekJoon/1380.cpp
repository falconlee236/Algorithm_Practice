#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    for(int idx = 1;; idx++){
        int n; cin >> n;
        cin.ignore();
        if (n == 0) break;
        string arr[n + 1];
        for(int i = 1; i <= n; i++) getline(cin, arr[i]);
        vector<int> v(n + 1);
        for(int i = 0; i < 2 * n - 1; i++){
            int a; char c; cin >> a >> c;
            v[a]++;
        }
        for(int i = 1; i <= n; i++) {
            if (v[i] == 1) {
                cout << idx << " " << arr[i] << "\n";
                break;
            }
        }
    }
}