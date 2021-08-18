/*9019*/
/*Got it!*/
#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int visit[10000];

int main() {
    int t; cin >> t;
    while(t--){
        int a, b; scanf("%d %d", &a, &b);
        string res;
        memset(visit, 0, sizeof(visit));
        queue<pair<int, string>> q;
        q.emplace(a, "");
        while(!q.empty()){
            int n = q.front().first;
            string inst = q.front().second;
            q.pop();
            if(n == b){
                res = inst;
                break;
            }
            
            int d_inst = (n * 2) % 10000;
            if(!visit[d_inst]){
                q.emplace(d_inst, inst + "D");
                visit[d_inst] = 1;
            }
            
            int s_inst = (n == 0 ? 9999 : n - 1);
            if(!visit[s_inst]){
                q.emplace(s_inst, inst + "S");
                visit[s_inst] = 1;
            }
            
            int cnt[4] = {};
            int temp = n, divide = 1000;
            for(int i = 0; i < 4; i++){
                cnt[i] = temp / divide;
                temp %= divide;
                divide /= 10;
            }
            
            int l_inst = cnt[1] * 1000 + cnt[2] * 100 + cnt[3] * 10 + cnt[0];
            if(!visit[l_inst]){
                q.emplace(l_inst, inst + "L");
                visit[l_inst] = 1; 
            }
            
            int r_inst = cnt[3] * 1000 + cnt[0] * 100 + cnt[1] * 10 + cnt[2];
            if(!visit[r_inst]){
                q.emplace(r_inst, inst + "R");
                visit[r_inst] = 1; 
            }
        }
        cout << res << "\n";
    }
   
	return 0;
}
