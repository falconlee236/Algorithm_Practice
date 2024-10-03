#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>
using namespace std;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int arr[1001][1001], visited[1001][1001][2];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m; cin >> n >> m;
	memset(arr, 1, sizeof(arr));
	int hx, hy, ex, ey; cin >> hx >> hy >> ex >> ey;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++) cin >> arr[i][j];
	}
	queue<tuple<int, int, int, int>> q;
	q.push({hx, hy, 0, 1});
	while(q.size()){
		auto [cx, cy, cnt, wall] = q.front();
		if (cx == ex && cy == ey){
			cout << cnt;
			return 0;
		}
		q.pop();
		if (visited[cx][cy][wall]) continue;
		visited[cx][cy][wall] = 1;
		for(int i = 0; i < 4; i++){
			int nx = cx + dx[i], ny = cy + dy[i];
			if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
			if (arr[nx][ny] == 0) q.push({nx, ny, cnt + 1, wall});
			if (arr[nx][ny] == 1 && wall) q.push({nx, ny, cnt + 1, wall - 1});
		}
	}
	cout << -1;
}