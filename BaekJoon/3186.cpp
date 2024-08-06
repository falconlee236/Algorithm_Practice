#include <iostream>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int k, l, n, cnt = 0, check = 0; cin >> k >> l >> n;
	bool start = false;
	for(int i = 1; i <= n; i++){
		char c; cin >> c;
		int num = c - '0';
		if (start){
			if (!num) cnt++;
			else cnt = 0;
			if (cnt == l){
				start = false;
				cnt = 0;
				check++;
				cout << i << "\n";
			}
		} else {
			if (num) cnt++;
			else cnt = 0;
			if (cnt == k){
				start = true;
				cnt = 0;
			}
		}
	}
	if (start) cout << l - cnt + n << "\n";
	else if (check == 0) cout << "NIKAD\n";
}