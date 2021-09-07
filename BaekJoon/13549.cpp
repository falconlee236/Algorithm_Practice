/*13549*/
/*Got it!*/
#include <iostream>
#include <deque>
using namespace std;

bool visit[200002];

int main(){
    int n, k; cin >> n >> k;
    deque<pair<int, int>> dq;
    dq.push_back({n, 0});
    while(!dq.empty()){
        int cur = dq.front().first;
        int t = dq.front().second;
        visit[cur] = true;
        if(cur == k){
            cout << t;
            return 0;
        }
        dq.pop_front();
        
        if(cur > 0 && !visit[cur - 1]){
            dq.push_back({cur - 1, t + 1});
        }
        
        if(!visit[cur + 1]){
            dq.push_back({cur + 1, t + 1});
        }
        
        if(cur * 2 <= 200000 && !visit[cur * 2]){
            dq.push_front({cur * 2, t});
        }
        
    }
}