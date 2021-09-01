//3 TRY
#include <iostream>
#include <vector>
using namespace std;

int ans, n, m;
vector<pair<int, int>> k;
void func(vector<pair<int, int>>& arr, int pos, int cnt){
    if(cnt == 0){
        int check[10] = {};
        for(int i = 0; i < k.size(); i++){
            check[k[i].first]++;
            check[k[i].second]++;
        }
        for(int i = 0; i < n; i++){
            if(check[i] != 1) return;
        }
        ans++;
        return;
    }
    
    for(int i = pos; i < arr.size(); i++){
        k.push_back(arr[i]);
        func(arr, i + 1, cnt - 1);
        k.pop_back();
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while(t--){
        ans = 0;
        cin >> n >> m;
        vector<pair<int, int>> v;
        for(int i = 0; i < m; i++){
            int a, b; cin >> a >> b;
            v.push_back({a, b});
        }
        func(v, 0, n / 2);
        cout << ans << "\n";
    }
    return 0;
}