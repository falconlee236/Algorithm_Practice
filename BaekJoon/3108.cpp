/*3108*/
/*Cheating*/
#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<vector<int>> v;

struct union_find{
    vector<int> root;
    vector<int> level;
    
    union_find(int n){
        root = vector<int>(n + 1);
        level = vector<int>(n + 1, 1);
        for(int i = 0; i <= n; i++) root[i] = i;
    };
    
    int find(int x){
        if(x == root[x]) return x;
        return root[x] = find(root[x]);
    }
    
    void set_union(int a, int b){
        int u = find(a);
        int v = find(b);
        
        if(u == v) return;
        if(level[u] > level[v]) root[v] = u;
        else root[u] = v;
        
        if(level[u] == level[v]) level[u]++;
    }
};

bool check(int i, int j){
    vector<int> a = v[i];
    vector<int> b = v[j];
    
    if(a[0] < b[0] && b[2] < a[2] && a[1] < b[1] && b[3] < a[3]) return false;
    if(b[0] < a[0] && a[2] < b[2] && b[1] < a[1] && a[3] < b[3]) return false;
    if (a[0] > b[2] || a[1] > b[3] || a[2] < b[0] || a[3] < b[1]) return false;
    return true;
}
int main(){
    int n; cin >> n;
    v = vector<vector<int>>(n + 1);
    vector<int> sect(n + 1);
    for(int i = 0; i < 4; i++) v[0].push_back(0);
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 4; j++){
            int num; scanf("%d", &num);
            v[i].push_back(num);
        }
    }
    
    union_find s(n);
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j <= n; j++){
            if(check(i, j)) s.set_union(i, j);
        }
    }
    
    
    set<int> top;
    for(int i = 0; i <= n; i++){
        top.insert(s.find(i));
    }
    
    cout << top.size() - 1 << endl;
    return 0;
}