#include <iostream>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while (T--){
		string a, b, c; cin >> a >> b;
		int tmp_a = 0, tmp_b = 0;
		for(size_t i = 0; i < a.size(); i++) c += to_string((a[i] != '0' && b[i] != '0'));
		for(size_t i = 0; i < a.size(); i++) tmp_a += !(a[i] == c[i]);
		for(size_t i = 0; i < b.size(); i++) tmp_b += !(b[i] == c[i]);
		cout << max(tmp_a, tmp_b) << "\n";
	}
}

/*
00110100 10010111 -> 3
10010111

and
00010100
or
10110111

1011 1100 -> 2
and
1000
or
1111

100101 110100 -> 1
and
100100
or
110101

1011101
0100010
->5

or
1111111
*/