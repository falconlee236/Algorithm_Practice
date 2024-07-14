#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
	string a, b; cin >> a >> b;
	while (a != b){
		if (b.size() == 0){
			cout << 0;
			return 0;
		}
		if (b.back() == 'B'){
			b.pop_back();
			reverse(b.begin(), b.end());
		} else if (b.back() == 'A') {
			b.pop_back();
		} else {
			cout << 0;
			return 0;
		}
	}
	cout << 1;
}