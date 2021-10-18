/*9237*/
/*Cheating*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	int arr[n];
	for(int i = 0; i < n; i++){
	    scanf("%d", &arr[i]);
	}
	sort(arr, arr + n, greater<int>());
	int ans = 0, idx = 2;
	for(int i = 0; i < n; i++){
	    ans = max(ans, idx + arr[i]);
	    idx++;
	}
	printf("%d", ans);
	return 0;
}
