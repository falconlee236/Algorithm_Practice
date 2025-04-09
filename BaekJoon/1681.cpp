#include <iostream>
#include <string>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, cnt = 0, ans = 0;
    char l; cin >> n >> l;
    for(int i = 1; cnt != n; i++){
        string s = to_string(i);
        bool flag = true;
        for(auto c : s) {
            if (c == l) flag = false;
        }
        if (flag) cnt++, ans = i;
    }
    cout << ans;
}