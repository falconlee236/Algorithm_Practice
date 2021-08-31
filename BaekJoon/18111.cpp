/*18111*/
/*Got it!*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int arr[501][501], height[257];
bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}


int main() {
	int n, m, b; cin >> n >> m >> b;
	int down = 257, up = -1;
	for(int i = 0; i < n; i++){
	    for(int j = 0; j < m; j++){
	        int num; cin >> num;
	        arr[i][j] = num;
	        up = max(num, up);
	        down = min(num, down);
	        height[num]++;
	    }
	}
	vector<pair<int, int>> v;
	for(int i = down; i <= up; i++){
	    int bag = b, ans = 0;
	    for(int j = down; j <= up; j++){
	        if(height[j]){
	            int num = abs(j - i) * height[j];
	            if(i < j){
    	            ans += (num * 2);
    	            bag += num;
    	        }
    	        if(i > j){
    	            ans += num;
    	            bag -= num;
    	        }
	        }
	    }
	    if(bag >= 0) v.push_back({ans, i});
	}
	
	sort(v.begin(), v.end(), cmp);
    cout << v[0].first << " " << v[0].second;
	return 0;
}
;