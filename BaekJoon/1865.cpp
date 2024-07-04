#include <iostream>
#include <vector>
#include <tuple>
#define INF INT32_MAX
using namespace std;
int main(void){
	cin.tie(0)->sync_with_stdio(0); cout.tie(0);
	int T; cin >> T;
	while (T--){
		int n, m, w; cin >> n >> m >> w;
		vector<tuple<int, int, int>> edges;
		vector<long long> dist(n + 1, 0);
		for(int i = 0; i < m; i++){
			int a, b, c; cin >> a >> b >> c;
			edges.push_back(make_tuple(a, b, c));
			edges.push_back(make_tuple(b, a, c));
		}
		for(int i = 0; i < w; i++){
			int a, b, c; cin >> a >> b >> c;
			edges.push_back(make_tuple(a, b, -c));
		}
		bool cycle = false;
		for(int j = 1; j <= n; j++){
			for(size_t k = 0; k < edges.size(); k++){
				int from, to, cost; tie(from, to, cost) = edges[k];
				if (dist[to] > dist[from] + cost){
					dist[to] = dist[from] + cost;
					if (j == n) cycle = true;
				}
			}
		}
		cout << (cycle ? "YES" : "NO") << "\n";
	}
}