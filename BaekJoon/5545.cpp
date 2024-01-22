#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int main(void){
	int n; cin >> n;
	int a, b; cin >> a >> b;
	int c; cin >> c;
	int cal[n];
	for(int i = 0; i < n; i++) cin >> cal[i];
	sort(cal, cal + n, greater<int>());
	int price = a, total = c;
	int ans = 0;
	ans = max(ans, total / price);
	for(int i = 0; i < n; i++){
		total += cal[i];
		price += b;
		ans = max(ans, total / price);
	}
	cout << ans << "\n";
}