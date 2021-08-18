/*1259*/
/*Got it!*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    while(1){
        string str; cin >> str;
        if(str == "0") break;
        string r_str = str;
        reverse(r_str.begin(), r_str.end());
        cout << (str == r_str ? "yes" : "no") << "\n";
    }
	return 0;
}
