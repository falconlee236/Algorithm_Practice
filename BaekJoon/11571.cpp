#include <iostream>
#include <vector>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int a, b; cin >> a >> b;
        vector<int> ans, check(b);
        ans.push_back(a / b);
        a = (a % b) * 10;
        for(int i = 1;; i++){
            int& idx = check[a / 10];
            if (idx){
                cout << ans[0] << ".";
                for(int i = 1; i < idx; i++) cout << ans[i]; cout << "(";
                for(size_t i = idx; i < ans.size(); i++) cout << ans[i]; cout << ")\n";
                break;
            }
            idx = i;
            ans.push_back(a / b);
            a = (a % b) * 10;
        }
    }
}