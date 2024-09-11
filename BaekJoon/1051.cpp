#include <iostream>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m, ans = 1; cin >> n >> m;
	char arr[n][m];
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> arr[i][j];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char num = arr[i][j];
			for(int a = i + 1; a < n; a++){
				if (num == arr[a][j]){
					for(int b = j + 1; b < m; b++){
						if (num == arr[i][b] && num == arr[a][b] && (a - i + 1) == (b - j + 1)){
							ans = max(ans, (b - j + 1) * (a - i + 1));		
						}
					}
				}
			}
		}
	}
	cout << ans;
}