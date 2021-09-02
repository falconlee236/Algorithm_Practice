#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
bool isfriend[10][10];

int func(bool taken[10]){
    int first = -1;
    for(int i = 0; i < n; i++){
        if(!taken[i]){
            first = i;
            break;
        }
    }
    if(first == -1) return 1;
    
    int ans = 0;
    for(int i = first + 1; i < n; i++){
        if(!taken[i] && isfriend[first][i]){
            taken[first] = true;
            taken[i] = true;
            ans += func(taken);
            taken[first] = false;
            taken[i] = false;
        }
    }
    return ans;
}

int main() {
	int t; cin >> t;
	while(t--){
	    cin >> n >> m;
	    for(int i = 0; i < m; i++){
	        int a, b; cin >> a >> b;
	        isfriend[a][b] = true;
	        isfriend[b][a] = true;
	    }
	    bool visit[10] = {};
	    cout << func(visit) << "\n";
	    fill(isfriend[0], isfriend[0] + 100, false);
	}
	return 0;
}
