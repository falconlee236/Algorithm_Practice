/*13417*/
/*Got it!*/
/*20:21*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--){
	    int n; cin >> n;
	    char alpha[1000];
	    for(int i = 0; i < n; i++) cin >> alpha[i];
	    string str(1, alpha[0]);
	    char left = alpha[0], right = alpha[0];
	    for(int i = 1; i < n; i++){
	        char ch = alpha[i];
	        if(ch <= left){
	            str = ch + str;
	            left = ch;
	        } else{
	            str = str + ch;
	            right = ch;
	        }
	    }
	    cout << str << "\n";
	}
	return 0;
}
