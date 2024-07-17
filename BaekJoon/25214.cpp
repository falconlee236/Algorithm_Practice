#include <iostream>
using namespace std;
int main(void){
	cin.tie(0)->sync_with_stdio(0);
	int n, mn = INT32_MAX, num, tmp = 0; cin >> n;
	for(int i = 0; i < n; i++){
		cin >> num;
		mn = min(mn, num);
		tmp = max(tmp, num - mn);
		cout << tmp << " ";
	}
}