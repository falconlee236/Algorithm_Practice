#include <iostream>
#include <map>
using namespace std;
map<string, int> mp;
void solve(string &s, string tmp, int idx, int k){
    if (k == 0) {
        mp[tmp] += 1;
        return;
    }
    for(size_t i = idx; i < s.length(); i++) solve(s, tmp + s[i], i + 1, k - 1);
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    string x, y, z; cin >> x >> y >> z;
    int k, flag = 0; cin >> k;
    solve(x, "", 0, k);
    solve(y, "", 0, k);
    solve(z, "", 0, k);
    for(auto [x, y]: mp){
        if (y < 2) continue;
        cout << x << "\n";
        flag = 1;
    }
    if (!flag) cout << -1;
}