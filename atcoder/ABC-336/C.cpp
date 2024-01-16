#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
	long long n; cin >> n;
	string s;
	string idx = "02468";
	if (n == 1){
		cout << "0" << "\n";
		return 0;
	}
	n--;
	while (n){
		s += idx[n % 5];
		n /= 5;
	}
	reverse(s.begin(), s.end());
	cout << s << "\n";
}