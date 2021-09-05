#include <iostream>
#include <algorithm>
using namespace std;

int top[20001];
int ans;

int div_conq(int left, int right){
    if(left == right) return top[left];
    int mid = (left + right) / 2;
    int ret = max(div_conq(left, mid), div_conq(mid + 1, right));
    
    int l = mid, r = mid + 1;
    int min_top = min(top[l], top[r]);
    ret = max(ret, min_top * 2);
    while(left < l || r < right){
        if(r < right && (l == left || top[l - 1] < top[r + 1])){
            r++;
            min_top = min(min_top, top[r]);
        }
        else{
            l--;
            min_top = min(min_top, top[l]);
        }
        ret = max(ret, min_top * (r - l  + 1));
    }
    return ret;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i = 0; i < n; i++) cin >> top[i];
        cout << div_conq(0, n - 1) << "\n";
    }
    return 0;
}