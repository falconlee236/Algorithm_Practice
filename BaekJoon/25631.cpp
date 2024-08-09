#include <iostream>
#include <map>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, ans = 0, num; cin >> n;
	map<int, int> mp;
	for(int i = 0; i < n; i++) {
		cin >> num;
		mp[num]++;
	}
	for(auto [x, y] : mp) ans = max(ans, y);
	cout << ans;
}