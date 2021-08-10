#include <iostream>
#include <vector>
using namespace std;

int arr[100001];
int* visited;
int* last;
vector<vector<int>> g;

void dfs(int x){
    visited[x] = 1;
    for(int i = 0; i < g[x].size(); i++){
        int y = g[x][i];
        if(!visited[y]) dfs(y);
        else last[x] = y;
    }
}

int main(){
    int t; scanf("%d", &t);
    while(t--){
        int n; scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);
        visited = new int[n + 1]{};
        last = new int[n + 1]{};
        g = vector<vector<int>>(n + 1);
        for(int i = 1; i <= n; i++) g[i].push_back(arr[i]);
        int res = 0;
        for(int i = 1; i <= n; i++){
            if(!visited[i] && dfs(i, i)) res++;
            delete visited;
            visited = new int[n + 1]{};
        }
        printf("%d\n", n - res);
    }
    return 0;
}