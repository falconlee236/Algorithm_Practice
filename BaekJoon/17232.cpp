#include <iostream>
#include <cstring>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m, t, k, a, b; cin >> n >> m >> t >> k >> a >> b;
	char arr[n + 1][m + 1];
	for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) cin >> arr[i][j];
	while (t--){
		int prefix[n + 1][m + 1];
		memset(prefix, 0, sizeof(prefix));
		for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + (arr[i][j] == '*');
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				int tx = max(1, i - k) - 1, ty = max(1, j - k) - 1, bx = min(n, i + k), by = min(m, j + k);
				int cnt = prefix[bx][by] - prefix[bx][ty] - prefix[tx][by] + prefix[tx][ty] - (arr[i][j] == '*');
				if (arr[i][j] == '*'){
					if (a <= cnt && cnt <= b) continue;
					else if (cnt < a || b < cnt) arr[i][j] = 'x';
				} else {
					if (a < cnt && cnt <= b) arr[i][j] = 'o';
				}
			}	
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if (arr[i][j] == 'x') arr[i][j] = '.';
				else if (arr[i][j] == 'o') arr[i][j] = '*';
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++) cout << arr[i][j];
		cout << "\n";
	}
}