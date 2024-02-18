#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    string arr[n];
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        sort(s.begin(), s.end());
        arr[i] = s;
    }
    sort(arr, arr + n);
    string res;
    for(int i = 0; i < k; i++) res += arr[i];
    sort(res.begin(), res.end());
    cout << res;
}
