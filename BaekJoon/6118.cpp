#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int main(void){
	cin.tie(0)->sync_with_stdio(0);
	int n, m; cin >> n >> m;
	vector<vector<int>> g(n + 1), ans(20010);
	vector<int> visit(n + 1, 0);
	for(int i = 0; i < m; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	queue<pair<int, int>> q;
	q.push({1, 0});
	visit[1] = 1;
	while (q.size()){
		auto [node, dist] = q.front();
		ans[dist].push_back(node);
		q.pop();
		for(int x : g[node]){
			if (visit[x] == 1) continue;
			q.push({x, dist + 1});
			visit[x] = 1;
		}
	}
	for(int i = 20009; i > 0; i--){
		if (ans[i].size() != 0){
			sort(ans[i].begin(), ans[i].end());
			cout << ans[i][0] << " " << i << " " << ans[i].size();
			break;
		}
	}
}