/*11050*/
/*Got it!*/
#include <iostream>
using namespace std;

long long arr[11] = {1, };

long long fact(int n){
    if(n == 1) return arr[n] = 1;
    return arr[n] = n * fact(n - 1);
}
int main(){
    int n, k; cin >> n >> k;
    fact(10);
    cout << arr[n] / arr[n - k] / arr[k];
	return 0;
}