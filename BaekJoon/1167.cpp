/*1167*/
/*Cheating*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<pair<int, int>>> g;
vector<int> visited;
int dim, endpoint;

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
    int v; scanf("%d", &v);
    g = vector<vector<pair<int, int>>>(v + 1);
    visited = vector<int>(v + 1);
    for(int i = 0; i < v; i++){
        int n; scanf("%d", &n);
        queue<int> tmp;
        while(1){
            int a; scanf("%d", &a);
            if(a == -1) break;
            tmp.push(a);
        }
        while(!tmp.empty()){
            int a = tmp.front(); tmp.pop();
            int b = tmp.front(); tmp.pop();
            g[n].push_back(make_pair(a, b));
        }
    }
    dfs(1, 0);
    fill(visited.begin(), visited.end(), 0);
    dfs(endpoint, 0);
    printf("%d", dim);
    return 0;
}