/*15904*/
/*00:05*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	string str; getline(cin, str);
	string up = "UCPC";
	auto iter = up.begin();
	for(auto s : str){
	    if(s == *iter) iter++;
	}
	if(iter == up.end()) cout << "I love UCPC";
	else cout << "I hate UCPC";
	return 0;
}
