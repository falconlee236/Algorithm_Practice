/*1707*/
/*cheating*/
#include <iostream>
#include <vector>
using namespace std;

int* visited;
vector<vector<int>> g;

bool dfs(int x, int color){
    visited[x] = color;
    
    for(int i = 0; i < g[x].size(); i++){
        int y = g[x][i];
        if(visited[y] == 0){
            if(not dfs(y, -color)) return false;
        }
        else{
            if(color == visited[y]) return false;
        }
    }
    return true;
}

int main(){
    int k; scanf("%d", &k);
    while(k--){
        int n, e; scanf("%d %d", &n, &e);
        g = vector<vector<int>>(n + 1);
        visited = new int[n + 1]{};
        while(e--){
            int u, v; scanf("%d %d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        bool flag = true;
        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                flag = dfs(i, 1);
                if(!flag) break;
            }
        }
        printf("%s\n", flag ? "YES" : "NO");
        delete visited;
    }
    return 0;
}