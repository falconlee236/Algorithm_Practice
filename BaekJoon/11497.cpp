#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--){
        int n; cin >> n;
        vector<int> a(n), v;
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        for(int i = 0; i < n; i++){
            if (i % 2 == 0) v.push_back(a[i]);
        }
        for(int i = n - 1; i >= 0; i--){
            if (i % 2 == 1) v.push_back(a[i]);
        }
        int res = 0;
        for(int i = 0; i < n - 1; i++)
            res = max(res, abs(v[i] - v[i + 1]));
        res = max(res, abs(v[0] - v[n - 1]));
        cout << res << "\n";
    }
}