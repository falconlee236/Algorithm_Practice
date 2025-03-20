#include <iostream>
#include <queue>
#include <vector>
using namespace std;
bool visited[100001];
int dist[100001], memo[100001];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, k, ans = 0; cin >> n >> k;
    if (n == k) {
        cout << 0 << "\n" << n;
        return 0;
    }
    queue<int> q;
    q.push(n);
    visited[n] = true;
    while (q.size()){
        int cur = q.front();
        q.pop();
        if (cur == k) {
            cout << dist[cur] << "\n";
            ans = dist[cur];
            break;
        }
        int step[3] = { cur - 1, cur + 1, cur * 2};
        for(int i = 0; i < 3; i++){
            int nx = step[i];
            if (nx >= 0 && nx <= 100000 && !visited[nx]) {
                q.push(nx);
                dist[nx] = dist[cur] + 1;
                visited[nx] = true;
                memo[nx] = cur;
            }
        }
        
    }
    vector<int> v;
    v.push_back(k);
    while (ans--){
        v.push_back(memo[k]);
        k = memo[k];
    }
    for(int i = v.size() - 1; i >= 0; i--) cout << v[i] << " ";
}