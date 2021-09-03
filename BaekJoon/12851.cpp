/*12851*/
/*Cheating*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool visit[200030];

int main(){
    int n, k; cin >> n >> k;
    queue<pair<int, int>> q;
    q.emplace(n, 0);
    int cnt = 0, min_value = -1;
    while(!q.empty()){
        int cur = q.front().first, times = q.front().second;
        q.pop();
        visit[cur] = true;
        if(cur == k){
            if(min_value == -1) min_value = times;
            if(min_value == times) cnt++;
        }
        if(cur > 0 && !visit[cur - 1]) q.emplace(cur - 1, times + 1);
        if(cur <= 200000 && !visit[cur + 1]) q.emplace(cur + 1, times + 1);
        if(cur <= 100000 && !visit[2 * cur]) q.emplace(2 * cur, times + 1);
    }
    cout << min_value << "\n" << cnt;
    return 0;
}