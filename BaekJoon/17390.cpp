#include <iostream>
#include <algorithm>

using namespace std;
int arr[300010];

int main(void){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, q; cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> arr[i];
	sort(arr + 1, arr + n + 1);
	for(int i = 1; i <= n; i++) arr[i] += arr[i - 1];
	while(q--){
		int l, r; cin >> l >> r;
		cout << arr[r] - arr[l - 1] << "\n";
	}
}