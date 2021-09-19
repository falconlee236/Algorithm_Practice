#include <iostream>
#include <algorithm>
using namespace std;

int town[51][51];
int cnt_dist[51];
double dp[101][51];
int n, d, p, q;

double solve(int day, int target){
    if(day == 0) return (target == p ? 1.0 : 0.0);
    double& ret = dp[day][target];
    if(ret > -0.5) return ret;
    ret = 0.0;
    for(int i = 0; i < n; i++){
        if(town[target][i] == 1){
            ret += solve(day - 1, i) / cnt_dist[i];
        }
    }
    return ret;
}

int main(){
    int c; cin >> c;
    while(c--){
        cin >> n >> d >> p;
        fill(cnt_dist, cnt_dist + 51, 0);
        fill(dp[0], dp[0] + 101 * 51, -1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> town[i][j];
                if(town[i][j] == 1) cnt_dist[i]++;
            }
        }
        int t; cin >> t;
        cout.precision(8);
        for(int i = 0; i < t; i++){
            cin >> q;
            cout << solve(d, q) << " ";
        }
        cout << "\n";

    }
}