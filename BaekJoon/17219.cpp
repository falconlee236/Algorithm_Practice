#include <iostream>
#include <unordered_map>
using namespace std;
int main(void){
	cin.tie(0)->sync_with_stdio(0); cout.tie(0);
	int n, m; cin >> n >> m;
	unordered_map<string, string> mp;
	for(int i = 0; i < n; i++){
		string str, pass; cin >> str >> pass;
		mp[str] = pass;
	}
	for(int i = 0; i < m; i++){
		string str; cin >> str;
		cout << mp[str] << "\n";
	}
}