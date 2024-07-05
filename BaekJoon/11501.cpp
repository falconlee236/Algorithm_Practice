#include <iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while(T--){
		int n; cin >> n;
		int arr[n]; for(int& x : arr) cin >> x;
		long long res = 0;
		int max_value = -1;
		for(int i = n - 1; i >= 0; i--){
			max_value = max(max_value, arr[i]);
			res += max_value - arr[i];
		}
		cout << res << "\n";
	}
}