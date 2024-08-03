#include <iostream>
#define MAX 1299709
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T, n; cin >> T;
	char arr[MAX + 1] = {0,};
	for(int i = 2; i * i <= MAX; i++){
		if (arr[i]) continue;
		for(int j = i + i; j <= MAX; j+=i){
			arr[j] = 1;
		}
	}
	while (T--){
		cin >> n;
		if (!arr[n]) cout << 0 << "\n";
		else {
			int left = n, right = n;
			while (arr[left]) left--;
			while (arr[right]) right++;
			cout << right - left << "\n";
		}
	}
}