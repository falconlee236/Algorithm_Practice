/*1654*/
/*Cheating*/
#include <iostream>
#include <algorithm>
using namespace std;

int k, n;
long long arr[10001];

int main() {
	scanf("%d %d", &k, &n);
	for(int i = 0; i < k; i++) scanf("%d", &arr[i]);
	sort(arr, arr + k);
	long long ans = 0;
	long long start = 1, end = arr[k - 1];
	while(start <= end){
	    int res = 0;
	    long long mid = (start + end) / 2;
	    
	    for(int i = 0; i < k; i++){
	        res += (arr[i] / mid);
	    }
	    if(res >= n){
	        start = mid + 1;
	        ans = max(mid, ans);
	    }
	    else end = mid - 1;
	}
	printf("%lld", ans);
	return 0;
}
