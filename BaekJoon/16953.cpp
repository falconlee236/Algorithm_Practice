#include <iostream>
using namespace std;
int main(void){
	int a, b, cnt = 0; cin >> a >> b;
	while (b){
		if (b == a) {
			cout << cnt + 1;
			return 0;
		}
		if (b % 10 == 1){
			string str = to_string(b);
			str.pop_back();
			if (str == ""){
				cout << -1;
				return 0;
			}
			b = stoi(str);
		}
		else if (b % 2 == 0) b /= 2;
		else {
			cout << -1;
			return 0;
		}
		cnt++;
	}
}