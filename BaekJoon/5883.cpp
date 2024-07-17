#include <iostream>
using namespace std;
int main(void){
	int n, ans = 0; cin >> n;
	int arr[n]; for(auto &x : arr) cin >> x;
	for(int i = 0; i < n; i++){
		int tmp = 1, num = -1;
		for(int j = i + 1; j < n; j++){
			if (arr[i] == arr[j]) tmp++;
			else if (arr[i] != arr[j] && num == -1) num = arr[j];
			else if (num == arr[j]) continue;
			else break;
		}
		ans = max(ans, tmp);
	}
	cout << ans;
}