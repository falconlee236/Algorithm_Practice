#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 987654321;

int bitcount(int n){
    if(n == 0) return 0;
    return n % 2 + bitcount(n / 2);
}

int n, k, m, l;
int pre[12], classes[10], cache[10][1 << 12];

int graduate(int semester, int taken){
    if(bitcount(taken) >= k) return 0;
    if(semester == m) return INF;
    int& ret = cache[semester][taken];
    if(ret != -1) return ret;
    ret = INF;
    int canTake = (classes[semester] & (~taken));
    for(int i = 0; i < n; i++){
        if((canTake & (1 << i)) && (taken & pre[i]) != pre[i]) 
            canTake &= ~(1 << i);
    }
    
    for(int take = canTake; take; take = (canTake & (take - 1))){
        if(bitcount(take) > l) continue;
        ret = min(ret, graduate(semester + 1, take | taken) + 1);
    }
    ret = min(ret, graduate(semester + 1, taken));
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        cin >> n >> k >> m >> l;
        fill(cache[0], cache[0] + 10 * (1 << 12), -1);
        for(int i = 0; i < n; i++){
            int num; cin >> num;
            int bit = 0;
            for(int j = 0; j < num; j++){
                int p; cin >> p;
                bit |= (1 << p);
            }
            pre[i] = bit;
        }
        for(int i = 0; i < m; i++){
            int num; cin >> num;
            int bit = 0;
            for(int j = 0; j < num; j++){
                int p; cin >> p;
                bit |= (1 << p);
            }
            classes[i] = bit;
        }
        int ans = graduate(0, 0);
        if(ans == INF) cout << "IMPOSSIBLE";
        else cout << ans;
        cout << "\n";
    }
}