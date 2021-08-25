/*15663*/
/*Got it!*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int n, m, arr[9];
vector<int> v;
set<vector<int>> res;
bool visit[8];

void func(int cnt){
    if(cnt == m){
        res.insert(v);
        return;
    }
    for(int i = 0; i < n; i++){
        if(!visit[i]){
            v.push_back(arr[i]);
            visit[i] = true;
            func(cnt + 1);
            visit[i] = false;
            v.pop_back();
        }
    }
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	func(0);
	for(auto x : res){
	    for(auto it = x.begin(); it != x.end(); ++it) cout << *it << " ";
	    cout << "\n";
	}
	return 0;
}
