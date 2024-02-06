#include <iostream>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int h, w, c; cin >> h >> w >> c;
	int cnt[c + 1];
	for(int i = 1; i <= c; i++) cin >> cnt[i];
	int board[h][w];
	int idx = 1;
	for(int i = 0; i < h; i++){
		if (i % 2 == 0){
			for(int j = 0; j < w; j++){
				if (cnt[idx] == 0) idx++;
				if (cnt[idx]--) board[i][j] = idx;
			}
		}
		else {
			for(int j = w - 1; j >= 0; j--){
				if (cnt[idx] == 0) idx++;
				if (cnt[idx]--) board[i][j] = idx;
			}
		}
	}
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++) cout << board[i][j];
		cout << "\n";
	}
}