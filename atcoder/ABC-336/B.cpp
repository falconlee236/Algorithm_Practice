#include<iostream>

using namespace std;

int main(void){
	int n; cin >> n;
	int i = 1, cnt = 0;
	while (!(n & i)){
		cnt++;
		i <<= 1;
	}
	cout << cnt << "\n";
}