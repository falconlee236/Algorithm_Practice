/*2108*/
/*Got it!*/
#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <map>
#include <vector>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	int arr[500001];
	map<int, int> mp;
	for(int i = 0; i < n; i++){
	    int num; cin >> num;
	    mp[num]++;
	    arr[i] = num;
	}
	sort(arr, arr + n);
	double one = accumulate(arr, arr + n, 0) / (double)n;
	cout << (round(one) == -0 ? 0 : round(one)) << "\n";
	cout << arr[n / 2] << "\n";
    vector<pair<int, int>> v(mp.begin(), mp.end());
    sort(v.begin(), v.end(), cmp);
    int idx, cnt = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i].second == v[0].second){
            if(cnt == 0) idx = i;
            cnt++;
        }
    }

	cout << (cnt == 1 ? v[idx].first : v[idx + 1].first) << "\n";
	cout << arr[n - 1] - arr[0];
	return 0;
}
