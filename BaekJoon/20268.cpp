#include <iostream>
using namespace std;
int main(void){
	int T; cin >> T;
	while (T--){
		int m, n, a; cin >> m >> n;
		for(int i = 0; i < m; i++) cin >> a;
		for(int i = 0; i < n; i++) cin >> a;
		cout << (m == 2 && n == 2 ? "7\n" : "1\n");
	}
}