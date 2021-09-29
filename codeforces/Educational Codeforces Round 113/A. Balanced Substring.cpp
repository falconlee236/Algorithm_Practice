#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--){
	    int n; cin >> n;
	    string str; cin >> str;
	    char start = str[0];
	    int a = -1, b = -1;
	    for(int i = 0; i < n; i++){
	        if(str[i] != start){
	            b = i + 1;
	            break;
	        }
	        a = i + 1;
	    }
	    cout << (b == -1 ? -1 : a) << " " << b << "\n";
	}
	return 0;
}
