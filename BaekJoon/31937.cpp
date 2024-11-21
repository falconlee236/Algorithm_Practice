#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m, k; cin >> n >> m >> k;
	vector<int> arr(n + 1);
	int comp[k]; for(int &x : comp) {
		cin >> x;
		arr[x] = 1;
	}
	pair<int, pair<int, int>> log[m];
	for(int i = 0; i < m; i++) cin >> log[i].first >> log[i].second.first >> log[i].second.second;
	sort(log, log + m);
	for(int x : comp){
		vector<int> visited(n + 1);
		int flag = 1;
		visited[x] = 1;
		for(auto [t, pos] : log){
			auto [a, b] = pos;
			if (visited[a]) visited[b] = 1;
		}
		for(int i = 1; i <= n; i++){
			if (arr[i] != visited[i]) {
				flag = 0;
				break;
			}
		}
		if (flag){
			cout << x;
			return 0;
		}
	}
}