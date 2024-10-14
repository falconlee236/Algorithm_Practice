#include <iostream>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	long long ans = 0;
	for(long long i = 0; i * 3 <= n; i++) ans += (n - 3 * i) / 2 + 1;
	cout << ans % 1000000;
}