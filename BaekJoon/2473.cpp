/*2473*/
/*Cheating*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	int n; cin >> n;
    int arr[5005];
	for(int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	if(arr[0] >= 0) cout << arr[0] << " " << arr[1] << " " << arr[2];
	else if(arr[n - 1] <= 0) cout << arr[n - 3] << " " << arr[n - 2] << " " << arr[n - 1];
	else{
	    int idx = -1, a, b;
	    long long ans = 9999987654321;
	    for(int i = 0; i < n - 2; i++){
	        int left = i + 1, right = n - 1;
    	    while(left < right){
    	        long long tmp = arr[left] + arr[right] + arr[i];
    	        if(abs(ans) >= abs(tmp)){
    	            a = arr[left];
    	            b = arr[right];
    	            idx = i;
    	            ans = tmp;
    	        }
    	        if(tmp > 0) right--;
    	        else left++;
    	    }
	    }
	    cout << arr[idx] << " " << a << " " << b;
	}
	return 0;
}
