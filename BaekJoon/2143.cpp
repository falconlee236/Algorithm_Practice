/*2143*/
/*Got it!*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int a[1001], b[1001];
	int t; cin >> t;
	int n; cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	int m; cin >> m;
	for(int i = 0; i < m; i++) cin >> b[i];
	
	vector<int> u, v;
	for(int i = 0; i < n; i++){
	    int tmp = a[i];
	    u.push_back(tmp);
	    for(int j = i + 1; j < n; j++){
	        tmp += a[j];
	        u.push_back(tmp);
	    }
	}
	
	for(int i = 0; i < m; i++){
	    int tmp = b[i];
	    v.push_back(tmp);
	    for(int j = i + 1; j < m; j++){
	        tmp += b[j];
	        v.push_back(tmp);
	    }
	}
	sort(v.begin(), v.end());
	sort(u.begin(), u.end());
	
	long long ans = 0;
	for(auto i = 0; i < u.size(); i++){
	    ans += (upper_bound(v.begin(), v.end(), t - u[i]) - lower_bound(v.begin(), v.end(), t - u[i]));
	}
	cout << ans;
	return 0;
}