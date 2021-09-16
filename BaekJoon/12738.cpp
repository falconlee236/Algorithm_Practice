/*12738*/
/*Got it!*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int arr[1000000];
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<int> v;
    for(int i = 0; i < n; i++){
        int cur = arr[i];
        if(v.size() == 0 || v.back() < cur) v.push_back(cur);
        else{
            int idx = lower_bound(v.begin(), v.end(), cur) - v.begin();
            v[idx] = cur;
        }
    }
    cout << v.size();
	return 0;
}