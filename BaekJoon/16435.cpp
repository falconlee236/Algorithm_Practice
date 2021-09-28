/*16435*/
/*Got it!*/
/*00:05*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a, b; cin >> a >> b;
	int arr[a];
	for(int i = 0; i < a; i++) cin >> arr[i];
	sort(arr, arr + a);
	for(int i = 0; i < a; i++){
	    if(b >= arr[i]){
	        b++;
	    }
	}
	cout << b;
	return 0;
}
