#include <iostream>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	int a[n], state, ans = 0;
	for(int &x : a) cin >> x;
	for(int i = 0; i < n; i++) {
		cin >> state;
		if (state) ans += a[i], a[i] = -a[i];
	}
	int tmp = a[0], end = a[0];
	for(int i = 1; i < n; i++){
		end = max(end + a[i], a[i]);
		tmp = max(tmp, end);
	}
	cout << ans + tmp;
}

//https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/