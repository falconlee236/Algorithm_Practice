#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 998244353;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
	    int n; cin >> n;
	    int arr[n]; for(int i = 0; i < n; i++) cin >> arr[i];
	    int m = *max_element(arr, arr + n);
	    int m_cnt = count(arr, arr + n, m);
	    int cnt = count(arr, arr + n, m - 1);
	    int ans = 1, sub = 1;
	    for(long long i = 1; i <= n; i++){
	        ans = (ans * i) % mod;
	        if(i != cnt + 1) sub = (sub * i) % mod;
	    }
	    cout << (m_cnt >= 2 ? ans % mod : (ans - sub + mod) % mod) << "\n";
	}
	return 0;
}
