#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m; cin >> n >> m;
	set<int> s;
	vector<pair<int, string>> arr;
	while (n--){
		string str;
		int cnt = 0, ans = 0;
		for(int i = 0; i < m; i++){
			char c; cin >> c;
			if (c == '*') {
				ans = max(ans, cnt);
				cnt = 0;
			}
			else cnt++;
		}
		ans = max(ans, cnt);
		cin >> str;
		s.insert(ans);
		arr.push_back({ans, str});
	}
	cout << s.size() << "\n";
	for(auto [x, y] : arr) cout << x << " " << y << "\n";
}