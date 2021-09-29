/*11508*/
/*Got it!*/
/*00:12*/
#include <iostream>
#include <algorithm>
using namespace std;

int arr[100010];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n, greater<int>());
	int res = 0;
	for(int i = 0; i < n; i+=3){
	    int sum = arr[i] + arr[i + 1] + arr[i + 2];
	    res += (sum - min({arr[i], arr[i + 1], arr[i + 2]}));
	}
	cout << res << "\n";
	return 0;
}
