#include <iostream>
using namespace std;
int n;
void solve(int cnt, int sum, int save, int sign, string res){
    if (cnt == n + 1){
        sum += save;
        if (sum == 0) cout << res << "\n";
        return;
    }
    solve(cnt + 1, sum, ((save * 10) + cnt * sign), sign, res + " " + to_string(cnt));
    solve(cnt + 1, sum + save, cnt, 1, res + "+" + to_string(cnt));
    solve(cnt + 1, sum + save, -cnt, -1, res + "-" + to_string(cnt));
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        cin >> n;
        solve(2, 0, 1, 1, "1");
        cout << "\n";
    }
}