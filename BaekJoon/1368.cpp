/*1368*/
/*Cheating*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct _disjoint{
    vector<int> root;
    _disjoint(int n) : root(n + 1){
        for(int i = 1; i <= n; i++) root[i] = i;
    }
    
    int find(int x){
        if(root[x] == x) return x;
        return root[x] = find(root[x]);
    }
    
    bool merge(int a, int b){
        int u = find(a);
        int v = find(b);
        
        if(u == v) return false;
        root[u] = v;
        return true;
    }
}D_set;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++) cin >> arr[i];
    D_set s(n);
    vector<pair<int, pair<int, int>>> line;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int num; cin >> num;
            if(i != j) line.push_back({num, {i, j}});
        }
    }

    for(int i = 1; i <= n; i++) line.push_back({arr[i], {0, i}});
    int ans = 0;
    sort(line.begin(), line.end());
    for(int i = 0; i < line.size(); i++){
        int cost = line[i].first;
        int a = line[i].second.first;
        int b = line[i].second.second;
        if(s.merge(a, b)) ans += cost;
    }
    cout << ans;
    return 0;
}