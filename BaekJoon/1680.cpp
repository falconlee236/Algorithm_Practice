#include <iostream>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while(T--){
		int w, n, ans = 0, cap = 0, a, b; cin >> w >> n;
		for (int i = 0; i < n; i++){
			cin >> a >> b;
			cap += b;
			if (cap > w) ans += a, cap = b;
			if (cap == w) ans += a, cap = 0;
		}
		if (cap) ans += a;
		cout << ans * 2 << "\n";
	}
}