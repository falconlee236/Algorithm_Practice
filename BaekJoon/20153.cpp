#include <iostream>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, res = 0, ans = 0; cin >> n;
	int arr[n]; for(int &x : arr){cin >> x;res ^= x;}
	for(int x : arr)ans = max(ans, res ^ x);
	ans = max(ans, res);
	cout << ans << ans;
}