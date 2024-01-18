#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
using pii = pair<string, int>;

int main(void){
	int k, l; cin >> k >> l;
	map<string, int> mp;
	for(int i = 0; i < l; i++){
		string str; cin >> str;
		mp[str] = i;
	}
	vector<pii> v(mp.begin(), mp.end());
	sort(v.begin(), v.end(), [](pii x, pii y){
		return x.second < y.second;
	});
	for(int i = 0; i < k && i < v.size(); i++) cout << v[i].first << "\n";
	return 0;
}