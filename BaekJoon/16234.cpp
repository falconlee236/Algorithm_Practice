#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, l, r, ans = 0; cin >> n >> l >> r;
	int arr[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++) cin >> arr[i][j];
	}
	while (true){
		int visited[n][n], cnt = 1, flag = 0;
		vector<pair<int, int>> res(n * n + 2, {0, 0});
		memset(visited, 0, sizeof(visited));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if (visited[i][j]) continue;
				queue<pair<int, int>> q;
				q.push({i, j});
				while (q.size()){
					auto [cx, cy] = q.front();
					q.pop();
					if(visited[cx][cy]) continue;
					res[cnt].first += arr[cx][cy];
					res[cnt].second++;
					visited[cx][cy] = cnt;
					for(int k = 0; k < 4; k++){
						int nx = cx + dx[k], ny = cy + dy[k];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (visited[nx][ny] == 0 && abs(arr[cx][cy] - arr[nx][ny]) >= l && abs(arr[cx][cy] - arr[nx][ny]) <= r)
							q.push({nx, ny});
					}
				}
				cnt++;
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				auto [x, y] = res[visited[i][j]];
				if (arr[i][j] != x / y) flag = 1;
				arr[i][j] = x / y;
			}
		}
		if (!flag) break;
		ans++;
	}
	cout << ans;
}