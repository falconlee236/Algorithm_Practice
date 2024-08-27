#include <iostream>
#include <vector>
#include <queue>
#define INF 2147483647
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while(T--){
		int n, d, start; cin >> n >> d >> start;
		vector<vector<pair<int, int>>> g(n + 1);
		vector<int> dist(n + 1, INF);
		while (d--){
			int a, b, c; cin >> a >> b >> c;
			g[b].push_back({a, c});
		}
		priority_queue<pair<int, int>> pq;
		pq.push({0, start});
		dist[start] = 0;
		while (pq.size()){
			int cur = pq.top().second;
			int cost = -pq.top().first;
			pq.pop();
			for(auto [node, x] : g[cur]){
				if (cost + x < dist[node]){
					dist[node] = cost + x;
					pq.push({-(cost + x), node});
				}
			}
		}
		int cnt = 0, ans = 0;
		for(int x : dist){
			if (x == INF) continue;
			cnt++;
			ans = max(ans, x);
		}
		cout << cnt << " " << ans << "\n";
	}
}