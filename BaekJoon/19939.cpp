/*19939*/
/*Cheating*/
#include <iostream>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	int res = 0;
	for(int i = 1; i <= k; i++) res += i;
	if(res > n){
	    cout << -1;
	    return 0;
	}
	if((n - res) % k == 0) cout << k - 1;
	else cout << k;
	
	return 0;
}
