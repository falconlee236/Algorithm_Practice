#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i < n; i++){
        string str; cin >> str;
        for(int j = 0; j < n; j++)
            if (str[j] == 'Y') g[i].push_back(j);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        bool visited[n] = {false, };
        queue<pair<int, int>> q;
        q.push({i, 0});
        visited[i] = true;
        int tmp = 0;
        while (q.size()){
            auto [top, dist] = q.front();
            if (dist == 1 || dist == 2) tmp++;
            q.pop();
            for(int x : g[top]){
                if (visited[x] == false){
                    visited[x] = true;
                    q.push({x, dist + 1});
                }
            }
        }
        ans = max(ans, tmp);
    }
    cout << ans;
}