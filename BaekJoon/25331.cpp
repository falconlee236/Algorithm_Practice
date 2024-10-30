#include <iostream>
#include <cstring>
using namespace std;

int K;
int original[7][7];
int board[7][7];
int deleted[7][7];
int ans = 1000000007;

void func(int col) {
	for (int r = 0; r < 7; r++) {
		for (int c = 0; c < 7; c++) board[r][c] = original[r][c];
	}
	for (int r = 6; r > -1; r--) {
		if (board[r][col]) continue;
		board[r][col] = K;
		break;
	}

	bool chk = 1;
	while (chk) {
		chk = 0;
		memset(deleted, 0, sizeof(deleted));

		for (int r = 0; r < 7; r++) {
			int cL = 0, combo = 0;
			for (int c = 0; c < 7; c++) {
				if (board[r][c]) combo++;
				else {
					for (int cc = cL; cc < c; cc++) {
						if (board[r][cc] == combo) deleted[r][cc] = 1;
					}
					cL = c + 1, combo = 0;
				}
			}
			for (int cc = cL; cc < 7; cc++) {
				if (board[r][cc] == combo) deleted[r][cc] = 1;
			}
		}
		for (int c = 0; c < 7; c++) {
			int rL = 0, combo = 0;
			for (int r = 0; r < 7; r++) {
				if (board[r][c]) combo++;
				else {
					for (int rr = rL; rr < r; rr++) {
						if (board[rr][c] == combo) deleted[rr][c] = 1;
					}
					rL = r + 1, combo = 0;
				}
			}
			for (int rr = rL; rr < 7; rr++) {
				if (board[rr][c] == combo) deleted[rr][c] = 1;
			}
		}
		
		for (int r = 0; r < 7; r++) {
			for (int c = 0; c < 7; c++) {
				if (deleted[r][c]) chk = 1, board[r][c] = 0;
			}
		}

		for (int c = 0; c < 7; c++) {
			for (int r = 6; r > -1; r--) {
				if (board[r][c]) {
					int rr = r + 1;
					while (rr < 7 && board[rr][c] == 0) {
						board[rr][c] = board[rr - 1][c];
						board[rr - 1][c] = 0;
						rr++;
					}
				}
			}
		}
	}

	int cnt = 0;
	for (int r = 0; r < 7; r++) {
		for (int c = 0; c < 7; c++) {
			if (board[r][c]) cnt++;
		}
	}
	ans = min(ans, cnt);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int r = 0; r < 7; r++) {
		for (int c = 0; c < 7; c++) cin >> original[r][c];
	}
	cin >> K;

	for (int col = 0; col < 7; col++) func(col);

	cout << ans;
}