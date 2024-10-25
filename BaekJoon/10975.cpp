#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	int arr[n], idx[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		idx[i] = arr[i];
	}
	sort(idx, idx + n);
	for(auto &x : arr) x = lower_bound(idx, idx + n, x) - idx;
	vector<pair<int, int>> v;
	for(auto x : arr){
		int flag = 1;
		for(auto &[a, b]: v){
			if (x - a == -1) {
				a = x;
				flag = 0;
				break;
			} else if (x - b == 1){
				b = x;
				flag = 0;
				break;
			}
		}
		if (flag) v.push_back({x, x});
	}
	cout << v.size();
}