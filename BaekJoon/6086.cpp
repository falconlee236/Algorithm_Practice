#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;
int cap[52][52], flow[52][52];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, ans = 0; cin >> n;
	unordered_map<char, int> mp;
	char c = 'A'; for(int i = 0; i < 26; i++) mp[c + i] = i;
	c = 'a'; for(int i = 0; i < 26; i++) mp[c + i] = i + 26;
	for(int i = 0, c; i < n; i++){
		char a, b; cin >> a >> b >> c;
		cap[mp[a]][mp[b]] += c;
		cap[mp[b]][mp[a]] += c;
	}
	int start = mp['A'], end = mp['Z'];
	while (1){
		vector<int> parent(52, -1);
		queue<int> q;
		parent[start] = start;
		q.push(start);
		while (q.size() && parent[end] == -1){
			int cur = q.front(); q.pop();
			for(int next = 0; next < 52; next++){
				if (cap[cur][next] > flow[cur][next] && parent[next] == -1){
					q.push(next);
					parent[next] = cur;
				}
			}
		}
		if (parent[end] == -1) break;
		int amount = 0xFFFFFF;
		for(int i = end; i != start; i = parent[i]) amount = min(amount, cap[parent[i]][i] - flow[parent[i]][i]);
		for(int i = end; i != start; i = parent[i]) flow[parent[i]][i] += amount, flow[i][parent[i]] -= amount;
		ans += amount;
	}
	cout << ans;
}