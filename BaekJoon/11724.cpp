/*11724*/
/*Got it!*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<vector<int>>& g, int*& check, int start){
    check[start] = 1;
    for(int i = 0; i < g[start].size(); i++){
        int s = g[start][i];
        if(check[s] == 0) dfs(g, check, s);
    }
}

int main() {
	int n, m; scanf("%d %d", &n, &m);
	vector<vector<int>> g(n + 1);
	int* check = new int[n + 1] {1, };
	while(m--){
	    int u, v; scanf("%d %d", &u, &v);
	    g[u].push_back(v);
	    g[v].push_back(u);
	}
	int res = 0;
    for(int i = 1; i <= n; i++){
        if(check[i] == 0) {
            dfs(g, check, i);
            res++;
        }
    }
    printf("%d", res);
	return 0;
}
