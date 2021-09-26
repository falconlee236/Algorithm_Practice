/*10973*/
/*00:14*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++) cin >> arr[i];
	if(!prev_permutation(arr, arr + n)) cout << -1;
	else{
	    for(int i = 0; i < n; i++) cout << arr[i] << " ";
	}
	return 0;
}
