/*1647*/
/*Got it!*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct _set{
    vector<int> root;
    _set(int n) : root(n + 1){
        for(int i = 0; i <= n; i++) root[i] = i;
    }
    
    int find(int num){
        if(num == root[num]) return num;
        return root[num] = find(root[num]);
    }
    
    bool merge(int a, int b){
        int u = find(a), v = find(b);
        if(u == v) return false;
        
        if(u < v) root[v] = u;
        else root[u] = v;
        return true;
    }
}Disjoint_set;

int main(){
    int n, m; cin >> n >> m;
    Disjoint_set s(n);
    vector<pair<int, pair<int, int>>> e;
    for(int i = 0; i < m; i++){
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        e.push_back(make_pair(c, make_pair(a, b)));
    }
    sort(e.begin(), e.end());
    int ans = 0, max_cost = -1, cnt = 0;
    for(int i = 0; i < m; i++){
        if(cnt == n - 1) break;
        int cost = e[i].first;
        int x = e[i].second.first;
        int y = e[i].second.second;
        if(s.merge(x, y)){
            cnt++;
            ans += cost;
            max_cost = max(max_cost, cost);
        }
    }
    printf("%d", ans - max_cost);
    return 0;
}