/*10451*/
/*Got it!*/
#include <iostream>
#include <vector>
using namespace std;

int arr[1001];
int* visited;
vector<vector<int>> g;

void dfs(int start){
    visited[start] = 1;
    for(int i = 0; i < g[start].size(); i++){
        int y = g[start][i];
        if(!visited[y]) dfs(y);
    }
}

int main() {
	int t; scanf("%d", &t);
	while(t--){
	    int n; scanf("%d", &n);
	    for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	    visited = new int[n + 1]{};
	    g = vector<vector<int>>(n + 1);
	    for(int i = 1; i <= n; i++) g[i].push_back(arr[i]);
	    int res = 0;
	    for(int i = 1; i <= n; i++){
	        if(!visited[i]){
	            dfs(i);
	            res++;
	        }
	    }
	    printf("%d\n", res);
	}
	return 0;
}
