#include <iostream>
#include <stack>
using namespace std;
using pii = pair<int, int>;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    stack<pii> stk;
    int ans = 0;
    while (T--){
        int type, a, t; cin >> type;
        if (type){
            cin >> a >> t;
            if (t == 1) ans += a;
            else stk.push({a, t - 1});
        } else {
            if (stk.empty()) continue;
            pii& tmp = stk.top();
            tmp.second--;
            if (tmp.second == 0){
                stk.pop();
                ans += tmp.first;
            }
        }
    }
    cout << ans;
    return 0;
}
