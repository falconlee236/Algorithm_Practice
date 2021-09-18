/*7562*/
/*Got it!*/
/*11:43*/
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;


int main(){
    int t; cin >> t;
    int pos[8][2] = {{1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};
    while(t--){
        bool visit[301][301] = {};
        int n; cin >> n;
        int a, b; cin >> a >> b;
        int na, nb; cin >> na >> nb;
        queue<tuple<int, int, int>> q;
        int ans = 0;
        q.emplace(a, b, ans);
        while(!q.empty()){
            int cura = get<0>(q.front());
            int curb = get<1>(q.front());
            int dist = get<2>(q.front());
            visit[cura][curb] = true;
            if(cura == na && curb == nb){
                ans = dist;
                break;
            }
            q.pop();
            for(int i = 0; i < 8; i++){
                int nexta = cura + pos[i][0];
                int nextb = curb + pos[i][1];
                if(0 <= nexta && nexta < n && 0 <= nextb && nextb < n){
                    if(!visit[nexta][nextb]){
                        q.emplace(nexta, nextb, dist + 1);
                        visit[nexta][nextb] = true;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}