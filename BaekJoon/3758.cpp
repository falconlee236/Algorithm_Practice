#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct team{
    int id;
    int summit_cnt;
    int time;
    int total;
    vector<int> score;
} team;

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--){
        int n, k, t, m, time = 0; cin >> n >> k >> t >> m;
        vector<team> teams(n);
        for(int i = 0; i < n; i++){
            teams[i].score = vector<int>(k);
            teams[i].id = i + 1;
        }
        while(time < m){
            int i, j, s; cin >> i >> j >> s;
            teams[i - 1].score[j - 1] = max(teams[i - 1].score[j - 1], s);
            teams[i - 1].time = time;
            teams[i - 1].summit_cnt++;
            time++;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < k; j++)
                teams[i].total += teams[i].score[j];
        }
        sort(teams.begin(), teams.end(), [](team a, team b){
            if (a.total == b.total){
                if (a.summit_cnt == b.summit_cnt)
                    return a.time < b.time;
                return a.summit_cnt <  b.summit_cnt;
            }
            return a.total > b.total;
        });
        for(int i = 0; i < n; i++){
            if (teams[i].id == t){
                cout << i + 1 << "\n";
                break;
            }
        }
    }
}