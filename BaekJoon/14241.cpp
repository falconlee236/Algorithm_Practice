/*14241*/
/*Got it!*/
/*00:09*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	int arr[100];
	for(int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	int ans = 0;
	int sum = 0;
	for(int i = n - 1; i > 0; i--){
	    if(i == n - 1) sum = arr[i];
	    else sum += arr[i];
	    ans += sum * arr[i - 1];
	}
	cout << ans;
	return 0;
}
