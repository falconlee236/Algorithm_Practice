/*3135*/
/*Got it!*/
/*00:08*/
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int a, b; cin >> a >> b;
	int n; cin >> n;
	int button[n];
	for(int i = 0; i < n; i++) cin >> button[i];
	sort(button, button + n);
	int idx = lower_bound(button, button + n, b) - button;
	int ans = 987654321;
	if(idx > 0) ans = min(ans, b - button[idx - 1] + 1);
	if(idx < n) ans = min(ans, button[idx] - b + 1);
	cout << min(abs(a - b), ans);
	return 0;
}
