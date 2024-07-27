#include <iostream>
#include <set>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while (T--){
		int a_n, b_n, c_n;
		cin >> a_n;
		int a[a_n]; for (int &x : a) cin >> x;
		cin >> b_n;
		int b[b_n]; for (int &x : b) cin >> x;
		cin >> c_n;
		int c[c_n]; for (int &x : c) cin >> x;
		int ans = 0;
		set<string> s;
		for(int i = 0; i < a_n; i++){
			for(int j = 0; j < b_n; j++){
				for(int k = 0; k < c_n; k++){
					bool flag = false;
					string str = to_string(a[i] + b[j] + c[k]);
					for(size_t l = 0; l < str.length(); l++){
						if (str[l] != '8' && str[l] != '5'){
							flag = true;
							break;
						}
					}
					if (!flag) s.insert(str);
				}
			}
		}
		cout << s.size() << "\n";
	}
}