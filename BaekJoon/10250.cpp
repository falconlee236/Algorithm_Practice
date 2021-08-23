/*10250*/
/*Got it!*/
#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--){
	    int h, w, n; cin >> h >> w >> n;
	    if(n % h == 0){
	        cout << h; 
	        if(n / h < 10) cout << 0;
	        cout << n / h << endl;
	    }
	    else{
	        cout << n % h; 
	        if(n / h + 1 < 10) cout << 0;
	        cout << n / h + 1 << endl;
	    }
	}
	return 0;
}
