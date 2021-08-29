/*1197*/
/*Cheating*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct _Set{
    vector<int> root;
    _Set(int n) : root(n + 1){
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

int main() {
	int v, e; scanf("%d %d", &v, &e);
	vector<pair<int, pair<int, int>>> edge;
	for(int i = 0; i < e; i++){
	    int a, b, c; scanf("%d %d %d", &a, &b, &c);
	    edge.push_back(make_pair(c, make_pair(a, b)));
	}
	sort(edge.begin(), edge.end());
	Disjoint_set s(v);
	long long res = 0;
	int cnt = 0;
	for(int i = 0; i < e; i++){
	    if(cnt == v - 1) break;
	    int cost = edge[i].first;
	    int x = edge[i].second.first;
	    int y = edge[i].second.second;
	    if(s.merge(x, y)){
	        res += cost;
	        cnt++;
	    }
	}
	cout << res;
	return 0;
}
