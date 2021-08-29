/*20040*/
/*Got it!*/
#include <iostream>
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
    
    bool union_set(int u, int v){
        int a = find(u);
        int b = find(v);
        if(a == b) return false;
        
        root[a] = b;
        return true;
    }
}set;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    set s(n);
    for(int i = 1; i <= m; i++){
        int a, b; cin >> a >> b;
        if(!s.union_set(a, b)){
            cout << i;
            return 0;
        }
    }
    cout << 0;
	return 0;
}
