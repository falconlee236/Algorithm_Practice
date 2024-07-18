#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m, k, x, ans = 0, mx = 0, mn = 0; cin >> n >> m >> k;
	string str;
	map<string, int> mp;
	while (n--){
		cin >> str >> x;
		mp[str] = x;
	}
	for(int i = 0; i < m; i++){
		cin >> str;
		ans += mp[str];
		mp.erase(str);
	}
	vector<pair<string, int>> v(mp.begin(), mp.end());
	sort(v.begin(), v.end(), [](auto a, auto b){
		if (a.second == b.second) return a.first < b.first;
		return a.second < b.second;
	});
	for(int i = 0; i < m - k; i++){
		mn += v[i].second;
		mx += v[v.size() - i - 1].second;
	}
	cout << ans + mn << " " << ans + mx;
}