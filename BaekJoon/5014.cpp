/*5014*/
/*Got it!*/
#include <iostream>
#include <queue>
using namespace std;

int visit[1000000];

int main(){
    int f, s, g, u, d; cin >> f >> s >> g >> u >> d;
    queue<pair<int, int>> q;
    q.emplace(s, 0);
    while(!q.empty()){
        int cur = q.front().first;
        int cnt = q.front().second;
        if(cur == g){
            printf("%d", cnt);
            return 0;
        }
        q.pop();
        int up = cur + u > f ? cur : cur + u;
        if(!visit[up]){
            q.emplace(up, cnt + 1);
            visit[up] = 1;
        }
        
        int down = cur - d < 1 ? cur : cur - d;
        if(!visit[down]){
            q.emplace(down, cnt + 1);
            visit[down] = 1;
        }
    }
    printf("use the stairs");
    return 0;
}