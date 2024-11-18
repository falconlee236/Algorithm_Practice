#include <iostream>
using namespace std;
int cnt[21];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, num; cin >> n;
	for(int i = 0; i < n; i++){
		cin >> num;
		for(int j = 0; j <= 20; j++) cnt[j] += (num & (1 << j) ? 1 : 0);
	}
	long long ans = 0;
	for(int i = 0; i <= 20; i++) ans += (1LL << i) * cnt[i] * (n - cnt[i]);
	cout << ans;
}

/*
3 5 7
a b c
3 5 -> 011 XOR 101 -> 110 = 6
3 7 -> 011 XOR 111 -> 100 = 4
5 7 -> 101 XOR 111 -> 010 = 2
-> 12 = 1100     XOR -> 000 AND -> 110
a * b + a * c + b * c

일단 중복은 제거해야함 -> 조합 5C2 = 10
최대 -> 10^6 * 10^6 / 2 10 ^ 11


a b c d e
a * b
a * c
a * d
a * e
b * c
b * d
b * e
c * d
c * e
d * e

1001
1101
0001
1001
0110


11110
01010
    101000
XOR -> 01111 -> 011110
84 -> 1010100

*/