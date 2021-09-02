#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<pair<int, int>> ch_point;
vector<pair<int, int>> h_point;
int ans = 987654321;
int n, m, house[55][55];
bool visit[55][55];

void find_min(){
    int res = 0;
    for(int i = 0; i < h_point.size(); i++){
        int tmp = 987654321;
        for(int j = 0; j < ch_point.size(); j++)
            tmp = min(tmp, abs(h_point[i].first - ch_point[j].first) + abs(h_point[i].second - ch_point[j].second));
        res += tmp;
    }
    ans = min(ans, res);
}

void chicken(int row, int col, int cnt){
    if(cnt == 0){
        find_min();
        return;
    }
    for(int i = row; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(house[i][j] == 2 && !visit[i][j]){
                ch_point.push_back({i, j});
                visit[i][j] = true;
                chicken(i, j, cnt - 1);
                visit[i][j] = false;
                ch_point.pop_back();
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> house[i][j];
            if(house[i][j] == 1) h_point.push_back({i, j});
        }
    }

    chicken(1, 1, m);
    cout << ans;
	return 0;
}