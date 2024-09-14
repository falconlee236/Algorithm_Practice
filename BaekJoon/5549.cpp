#include <iostream>
using namespace std;
int jungle[1010][1010], ocean[1010][1010], ice[1010][1010];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m, k, a, b, c, d; cin >> n >> m >> k;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			char c; cin >> c;
			jungle[i][j] = jungle[i - 1][j] + jungle[i][j - 1] - jungle[i - 1][j - 1] + (c == 'J');
			ocean[i][j] = ocean[i - 1][j] + ocean[i][j - 1] - ocean[i - 1][j - 1] + (c == 'O');
			ice[i][j] = ice[i - 1][j] + ice[i][j - 1] - ice[i - 1][j - 1] + (c == 'I');
		}
	}
	while (k--){
		cin >> a >> b >> c >> d;
		cout << jungle[c][d] - jungle[a - 1][d] - jungle[c][b - 1] + jungle[a - 1][b - 1] << " " << ocean[c][d] - ocean[a - 1][d] - ocean[c][b - 1] + ocean[a - 1][b - 1] << " " << ice[c][d] - ice[a - 1][d] - ice[c][b - 1] + ice[a - 1][b - 1] << "\n";
	}
}