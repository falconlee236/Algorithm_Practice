#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int l[200010], r[200010], v[200010];

int main(void){
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> v[i];
	for(int i = 1; i <= n; i++) l[i] = min(v[i], l[i - 1] + 1);
	for(int i = n; i > 0; i--) r[i] = min(v[i], r[i + 1] + 1);
	int ans = 0;
	for(int i = 0; i <= n; i++) ans = max(min(l[i], r[i]), ans);
	cout << ans << "\n";
}