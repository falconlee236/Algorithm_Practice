#include <iostream>
#include <unordered_set>
#include <functional>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n; 
	int arr[n], ans = 0;
	for(int& x : arr){ cin >> x; ans += x; }
	unordered_set<int> s;
	function<void(int, int)> f = [&](int idx, int res){
		if (idx == n){
			if (res == 0 || s.count(res)) return;
			s.insert(res); ans--; return;
		}
		f(idx + 1, res);
		f(idx + 1, res + arr[idx]);
	}; f(0, 0);
	cout << ans;
}