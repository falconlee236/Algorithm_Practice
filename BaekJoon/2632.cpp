/*2632*/
/*Got it!*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
	int s; cin >> s;
	int m, n; cin >> m >> n;
	int a[1001], b[1001];
	for(int i = 0; i < m; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	
	vector<int> sum_a;
	for(int i = 0; i < m; i++){
	    int tmp = a[i], j = (i + 1) % m, cnt = 0;
	    sum_a.push_back(a[i]);
	    while(cnt < m - 2){
	        tmp += a[j];
	        sum_a.push_back(tmp);
	        j = (j + 1) % m;
	        cnt++;
	    }
	}
    sum_a.push_back(accumulate(a, a + m, 0));
    
    vector<int> sum_b;
	for(int i = 0; i < n; i++){
	    int tmp = b[i], j = (i + 1) % n, cnt = 0;
	    sum_b.push_back(b[i]);
	    while(cnt < n - 2){
	        tmp += b[j];
	        sum_b.push_back(tmp);
	        j = (j + 1) % n;
	        cnt++;
	    }
	}
	sum_b.push_back(accumulate(b, b + n, 0));
	sort(sum_a.begin(), sum_a.end());
	sort(sum_b.begin(), sum_b.end());
	int ans = 0;
	
	for(auto i = 0; i < sum_a.size(); i++){
	    int target = s - sum_a[i];
	    if(sum_a[i] == s) ans++;
	    else ans += upper_bound(sum_b.begin(), sum_b.end(), target) - lower_bound(sum_b.begin(), sum_b.end(), target); 
	}
	for(auto i = 0; i < sum_b.size(); i++){
	    if(sum_b[i] == s) ans++;
	}
	cout << ans;
	return 0;
}
