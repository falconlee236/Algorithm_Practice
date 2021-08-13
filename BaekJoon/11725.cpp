/*11725*/
/*Got it!*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<vector<int>> g;
int visited[100002];

int main(){
    int n; scanf("%d", &n);
    memset(visited, 0, sizeof(visited));
    g = vector<vector<int>>(n + 1);
    for(int i = 0; i < n - 1; i++){
        int u, v; scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i = 0; i < g[cur].size(); i++){
            int x = g[cur][i];
            if(!visited[x]){
                q.push(x);
                visited[x] = cur;
            }
        }
    }
    for(int i = 2; i <= n; i++){
        printf("%d\n", visited[i]);
    }
    return 0;
}