#include <iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    string arr[n]; for(auto &x : arr) cin >> x;
    for(int i = 0; i < arr[0].length(); i++){
        bool flag = true;
        for(int j = 1; j < n; j++) flag = flag && (arr[0][i] == arr[j][i]);
        cout << (flag ? arr[0][i] : '?');
    }
}