/*2568*/
/*Got it!*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<pair<int, int>> line;
	for(int i = 0; i < n; i++){
	    int a, b; cin >> a >> b;
	    line.push_back({a, b});
	}
	sort(line.begin(), line.end());
	vector<int> lis;
	int idx[500001] = {};
	for(int i = 0; i < n; i++){
	    int cur = line[i].second;
	    if(lis.size() == 0 || lis.back() < cur){
	        idx[i] = lis.size();
	        lis.push_back(cur);
	    }
	    else{
	        int pos = lower_bound(lis.begin(), lis.end(), cur) - lis.begin();
	        idx[i] = pos;
	        lis[pos] = cur;
	    }
	}
	
	int size = lis.size() - 1;
	for(int i = n - 1; i >= 0; i--){
	    if(idx[i] == size){
	        size--;
	        idx[i] = -1;
	    }
	}
	
	cout << n - lis.size() << "\n";
	for(int i = 0; i < n; i++){
	    if(idx[i] != -1) cout << line[i].first << "\n";
	}
	return 0;
}
