/*2178*/
/*Got it!*/
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    int maze[102][102];
	int n, m; scanf("%d %d", &n, &m);
	getchar();
	fill(maze[0], maze[0] + 102 * 102, -1);
	for(int i = 1; i <= n; i++){
	    string str; getline(cin, str);
	    for(int j = 1; j <= m; j++) maze[i][j] = str[j - 1] - '0';
	}
	int pos[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    queue<pair<int, int>> q;
    q.push(make_pair(1, 1));
    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = cur.first + pos[i][0];
            int ny = cur.second + pos[i][1];
            if(maze[nx][ny] == 1){
                maze[nx][ny] = maze[cur.first][cur.second] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
    printf("%d", maze[n][m]);
	return 0;
}
