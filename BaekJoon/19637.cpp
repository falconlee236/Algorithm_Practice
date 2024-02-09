#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(void){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	int cnt[n]; string name[n];
	for(int i = 0; i < n; i++) cin >> name[i] >> cnt[i];
	while (m--){
		int num; cin >> num;
		cout << name[lower_bound(cnt, cnt + n, num) - cnt] << "\n";
	}
}