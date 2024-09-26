#include <iostream>
#include <algorithm>
using namespace std;
pair<int, int> arr[101][16];
int check[101][16];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m, q; cin >> n >> m >> q;
	while (q--){
		string s;
		int a, b, c; cin >> a >> b >> c >> s;
		if (s == "AC" && check[b][c]== 0) {
			arr[b][c].first = a;
			check[b][c] = 1;
		}
		else if (s != "AC" && check[b][c] == 0) arr[b][c].second++;
	}
	tuple<int, int, int> ans[n];
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			auto [x, y] = arr[i][j];
			ans[i - 1] = {-(-get<0>(ans[i - 1]) + (check[i][j] != 0)), get<1>(ans[i - 1]) + (x + 20 * y) * (check[i][j] != 0), i};
		}
	}
	sort(ans, ans + n);
	for(auto [a, b, c]: ans) cout << c << " " << -a << " " << b << "\n";
}