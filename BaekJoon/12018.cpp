/*12018*/
/*GOT IT!*/
/*37:00*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<int> ans;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        vector<int> v(a);
        if(a < b){
            ans.push_back(1);
            for(int j = 0; j < a; j++) cin >> v[j];
        }
        else{
            for(int j = 0; j < a; j++) cin >> v[j];
            sort(v.begin(), v.end(), greater<int>());
            ans.push_back(v[b - 1]);
        }
    }
    sort(ans.begin(), ans.end());
    int sum = 0, cnt = 0;
    for(int i = 0; i < ans.size(); i++){
        sum += ans[i];
        if(sum > m) break;
        cnt++;
    }
    cout << cnt;
}