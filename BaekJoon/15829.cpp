/*15829*/
/*Got it!*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	int l; cin >> l;
	string str; cin >> str;
	long long res = 0;
	long long k = 1;
	for(int i = 0; i < l; i++) {
	    k %= 1234567891;
	    long long tmp = ((str[i] - 'a' + 1) % 1234567891);
	    res += (k * tmp);
	    k *= 31;
	}
	cout << res % 1234567891 << endl;
	return 0;
}