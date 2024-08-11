#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m; cin >> n >> m;
	unordered_map<string, int>mp;
	string s, arr[3];
	for(int i = 0; i < n; i++){
		cin >> arr[0] >> arr[1] >> arr[2];
		for(int i = 0; i < 3; i++){
			mp[arr[i]]++;
			for(int j = 0; j < 3; j++){
				if (i == j) continue;
				mp[arr[i] + arr[j]]++;
			}
		}
		mp[arr[0] + arr[1] + arr[2]]++;
	}
	while (m--){
		string key;
		for(int i = 0; i < 3; i++){
			cin >> s;
			if (s != "-") key += s;
		}
		cout << (key.empty() ? n : mp[key]) << "\n";
	}
}