#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int n, m; cin >> n >> m;
        int a[n], b[m];
        for(int &x : a) cin >> x;
        for (int &x : b) cin >> x;
        int i = 0, j = 0;
        sort(a, a + n);
        sort(b, b + m);
        while(i < n && j < m){
            if (a[i] < b[j]) i++;
            else j++;
        }
        if (i == n) cout << 'B';
        else if (j == m) cout << 'S';
        else cout << 'C';
        cout << "\n";
    }
}