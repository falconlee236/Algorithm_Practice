#include <iostream>
using namespace std;
int main() {
	int res = -1, num, x = 0, y = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> num;
			if (num > res) {
				res = num;
				x = i + 1;
				y = j + 1;
			}
		}
	}
	cout << res << "\n" << x << " " << y;
	return 0;
}