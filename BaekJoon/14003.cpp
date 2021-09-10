/*14003*/
/*Cheating*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int arr[1000001], idx[1000001];
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<int> v;
    for(int i = 0; i < n; i++){
        int cur = arr[i];
        if(v.size() == 0 || v.back() < cur){
            idx[i] = v.size();
            v.push_back(cur);
        }
        else{
            int pos = lower_bound(v.begin(), v.end(), cur) - v.begin();
            idx[i] = pos;
            v[pos] = cur;
        }
    }
    vector<int> ans;
    int size = v.size() - 1;
    for(int i = n - 1; i >= 0; i--){
        if(idx[i] == size){
            ans.push_back(arr[i]);  
            size--;
        } 
    }
    reverse(ans.begin(), ans.end());
    cout << v.size() << "\n";
    for(auto x : ans) cout << x << " ";
    return 0;
}
