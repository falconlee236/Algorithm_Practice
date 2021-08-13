#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<pair<int, int>>> g;
vector<int> visited;
int dim = 0;
int endpoint = 0;

void dfs(int x, int len){
    visited[x] = 1;
    
    if(len > dim){
        dim = len;
        endpoint = x;
    }
    
    for(int i = 0; i < g[x].size(); i++){
        pair<int, int> y = g[x][i];
        if(!visited[y.first]) dfs(y.first, len + y.second);
    }
}

int main(){
    int n; scanf("%d", &n);
    g = vector<vector<pair<int, int>>>(n + 1);
    visited = vector<int>(n + 1, 0);
    for(int i = 1; i <= n; i++){
        int u, v, d; scanf("%d %d %d", &u, &v, &d);
        g[u].push_back(make_pair(v, d));
        g[v].push_back(make_pair(u, d));
    }
    dfs(1, 0);
    fill(visited.begin(), visited.end(), 0);
    dfs(endpoint, 0);
    printf("%d", dim);
    return 0;
}