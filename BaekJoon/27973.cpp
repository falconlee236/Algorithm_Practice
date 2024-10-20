#include <iostream>
using namespace std;
using ll = long long;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int q; cin >> q;
	ll st = 1, mt = 1, sm = 0;
	while (q--){
		int x; cin >> x;
		if (x == 3) cout << st * mt + sm << "\n";
		else {
			ll n; cin >> n;
			if (x == 0) sm += n;
			else if (x == 1) sm *= n, mt *= n;
			else st += n;
		}
	}
}