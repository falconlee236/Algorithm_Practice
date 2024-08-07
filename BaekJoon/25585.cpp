#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int board[101][101], n, mn = INT32_MAX; cin >> n;
	vector<pair<int, int>> robots;
	pair<int, int> start;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2){
				start.first = i;
				start.second = j;
			} else if (board[i][j] == 1) robots.push_back({i, j});
		}
	}
	sort(robots.begin(), robots.end());
	do{
		int cur_x = start.first, cur_y = start.second, tmp = 0, check = 1;
		for(auto [x, y] : robots){
			int dx = abs(cur_x - x), dy = abs(cur_y - y);
			if ((dx + dy) % 2 == 0){
				tmp += max(dx, dy);
				cur_x = x;
				cur_y = y;
			} else {
				check = 0;
				break;
			}
		}
		if (check) mn = min(mn, tmp);
	} while(next_permutation(robots.begin(), robots.end()));
	if (mn == INT32_MAX) cout << "Shorei";
	else cout << "Undertaker\n" << mn;
}