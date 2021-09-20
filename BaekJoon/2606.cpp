/*2606*/
/*Got it!*/
/*05:00*/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> g;
bool visit[101];
int ans;
int pos[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void dfs(int x){
    visit[x] = true;
    ans++;
    for(int i = 0; i < g[x].size(); i++){
        int next = g[x][i];
        if(!visit[next]) dfs(next);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	g = vector<vector<int>>(n + 1);
	for(int i = 0; i < m; i++){
	    int a, b; cin >> a >> b;
	    g[a].push_back(b);
	    g[b].push_back(a);
	}
	dfs(1);
	cout << ans - 1;
	return 0;
}
