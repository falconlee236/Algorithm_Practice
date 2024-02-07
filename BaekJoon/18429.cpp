#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k; cin >> n >> k;
	int arr[n]; for(auto &x : arr) cin >> x;
	int idx[n]; iota(idx, idx + n, 0);
	int ans = 0;
	do{
		int res = 500, flag = 1;
		for(auto x : idx){
			res -= (k - arr[x]);
			if (res < 500){
				flag = 0;
				break;
			}
		}
		ans += flag;
	}while(next_permutation(idx, idx + n));
	cout << ans;
}