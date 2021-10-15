/*3474*/
/*00:16*/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
	    int n; cin >> n;
	    int res = 0;
	    int arr[13] = {};
	    for(int i = 1; i <= 12; i++){
	        res += n / (int)pow(5, i);
	    }
	    cout << res << "\n";
	}
	return 0;
}
