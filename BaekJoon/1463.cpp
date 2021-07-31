/*1463*/
#include <iostream>
#include <algorithm>

using namespace std;

int mem[1000001] = {0, 0, 1, 1, 0, };

int solve(int n){
	if (n < 4) return mem[n];
	for(int i = 4; i < n + 1; i++){
		int a = 1000000, b = 10000000, c = 10000000;
		if(i % 2 == 0) a = mem[i / 2] + 1;
		if(i % 3 == 0) b = mem[i / 3] + 1;
		c = mem[i - 1] + 1;
		mem[i] = min({a, b, c});
	}
	return mem[n];
}

int main(void){
	int n; cin >> n;
	cout << solve(n) << endl;
	return 0;
}