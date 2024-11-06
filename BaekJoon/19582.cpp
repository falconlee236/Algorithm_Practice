#include <iostream>
using namespace std;
using ll = long long;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, flag = 1; cin >> n;
	ll sum = 0, mn = 0;
	ll arr[n][2]; for(int i = 0; i < n; i++) cin >> arr[i][0] >> arr[i][1];
	for(int i = 0; i < n; i++){
		if (sum > arr[i][0]) {
			flag = 0;
			break;
		}
		sum += arr[i][1]; 
	}
	if (flag) {
		cout << "Kkeo-eok";
		return 0;
	}
	flag = 1, sum = 0;
	int tmp = 1;
	for(int i = 0; i < n; i++){
		if (sum > arr[i][0]) {
			if (tmp) {
				tmp = 0;
				continue;
			}
			flag = 0;
			break;
		}
		sum += arr[i][1]; 
	}
	if (flag || tmp) {
		cout << "Kkeo-eok";
		return 0;
	}
	flag = 1, sum = 0, tmp = 1;
	for(int i = 0; i < n; i++){
		if (sum > arr[i][0]) {
			if (tmp) {
			 	sum -= mn;
				tmp = 0;
				if (sum > arr[i][0]) {
					flag = 0;
					break;
				}
				sum += arr[i][1];
				mn = max(mn, arr[i][1]);
				continue;
			}
			flag = 0;
			break;
		}
		sum += arr[i][1];
		mn = max(mn, arr[i][1]);
	}
	cout << (flag || tmp ? "Kkeo-eok" : "Zzz");
}