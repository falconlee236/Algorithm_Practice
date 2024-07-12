#include <iostream>
using namespace std;
int N, arr[110][110], xpos[4] = {1, 0, -1, 0}, ypos[4] = {0, 1, 0, -1};
void dfs(int visited[][110], int len, int x, int y){
	visited[x][y] = 1;
	for(int i = 0; i < 4; i++){
		int dx = x + xpos[i], dy = y + ypos[i];
		if (0 < dx && dx <= N && 0 < dy && dy <= N && visited[dx][dy] != 1 && arr[dx][dy] > len){
			dfs(visited, len, dx, dy);
		}
	}
}
int main(void){
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	int max_k = 0;
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			max_k = max(max_k, arr[i][j]);
		}
	}
	int mx_ans = 0;
	for(int k = 0; k <= max_k; k++){
		int visited[110][110] = {0, };
		int ans = 0;
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				if (arr[i][j] <= k || visited[i][j]) continue;
				dfs(visited, k, i, j);
				ans++;
			}
		}
		mx_ans = max(ans, mx_ans);
	}
	cout << mx_ans;
}