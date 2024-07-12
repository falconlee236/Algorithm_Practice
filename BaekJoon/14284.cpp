#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;
int main(void){
	cin.tie(0)->sync_with_stdio(0);
	int n, m; cin >> n >> m;
	vector<vector<pii>> g(n + 1);
	vector<int> dist(n + 1, INT32_MAX);
	while (m--){
		int a, b, c; cin >> a >> b >> c;
		g[a].push_back({c, b});
		g[b].push_back({c, a});
	}
	int from, to; cin >> from >> to;
	priority_queue<pii> pq;
	pq.push({0, from});
	dist[from] = 0;
	while(pq.size()){
		pii node = pq.top();
		pq.pop();
		int cost = -node.first, target = node.second;
		for(pii x : g[target]){
			int next = x.second, n_cost = x.first;
			if (dist[next] > cost + n_cost){
				dist[next] = cost + n_cost;
				pq.push({-dist[next], next});
			}
		}
	}
	cout << dist[to];
}