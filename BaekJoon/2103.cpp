#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<vector<int>> x(10010), y(10010);
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        x[a].push_back(b);
        y[b].push_back(a);
    }
    int res = 0;
    for(int i = 0; i < 10010; i++){
        sort(x[i].begin(), x[i].end());
        sort(y[i].begin(), y[i].end());
        for(int j = 0; j < x[i].size(); j+=2) res += x[i][j + 1] - x[i][j];
        for(int j = 0; j < y[i].size(); j+=2) res += y[i][j + 1] - y[i][j];
    }
    cout << res;
}

/*
1 1
1 2
1 3
2 1 
2 2
2 3
1 + 1 + 2 + 1 + 1 + 2
o o
o o 
o o 
*/