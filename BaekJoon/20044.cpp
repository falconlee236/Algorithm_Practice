//20044
#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
	cin.tie(0)->ios_base::sync_with_stdio(0);
	int n; cin >> n;
	int arr[2 * n];
	for(int &x : arr) cin >> x;
	sort(arr, arr + 2 * n);
	int ans = 2000000;
	for(int i = 0; i < n; i++) ans = min(ans, arr[i] + arr[2 * n - i - 1]);
	cout << ans;
}