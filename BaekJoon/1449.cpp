#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
	cin.tie(0)->sync_with_stdio(0); cout.tie(0);
	int n, l, ans = 0; cin >> n >> l;
	int arr[n]; for(int &x : arr) cin >> x;
	sort(arr, arr + n);
	int tmp = l;
	for(int i = 0; i < n; i++){
		if (i == n - 1) break;
		if (tmp <= arr[i + 1] - arr[i]){
			ans++;
			tmp = l;
		} else {
			tmp -= arr[i + 1] - arr[i];
		}
	}
	cout << ans + 1;
}