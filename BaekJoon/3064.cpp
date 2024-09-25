#include<iostream>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while (T--){
		int n, ans = 0; cin >> n;
		int arr[n][n];
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				char c; cin >> c;
				arr[i][j] = (c == '#' ? -1 : c - '0');
			}
		}
		for(int i = 1; i < n - 1; i++){
			for(int j = 1; j < n - 1; j++){
				int tmp = 3;
				for(int dx = -1; dx <= 1; dx++){
					for(int dy = -1; dy <= 1; dy++){
						if (arr[i + dx][j + dy] == -1 || (dx == 0 && dy == 0)) continue;
						tmp = min(tmp, arr[i+dx][j+dy]);
					}
				}
				if (tmp > 0){
					ans++;
					for(int dx = -1; dx <= 1; dx++){
						for(int dy = -1; dy <= 1; dy++){
							if (arr[i + dx][j + dy] == -1 || (dx == 0 && dy == 0)) continue;
							arr[i + dx][j + dy]--;
						}
					}
				}
			}
		}
		cout << ans << "\n";
	}
}