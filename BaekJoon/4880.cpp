#include <iostream>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	while (1){
		int a, b, c; cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) break;
		if (a + c == 2 * b) cout << "AP " << 2 * c - b << "\n";
		else cout << "GP " << c * (c / b) << "\n";
	}
}