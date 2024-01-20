#include <iostream>
#include <string>
using namespace std;

int main(void){
	int T; cin >> T;
	while (T--){
		int n; cin >> n;
		string a, b, c; cin >> a >> b >> c;
		int flag = 0;
		for(int i = 0; i < n; i++){
			if(!((a[i] == b[i] && (b[i] == c[i] || a[i] != c[i])) || (a[i] != b[i] && a[i] != c[i] && b[i] != c[i]))){
				flag = 1;
				break;
			}
		}
		cout << (flag ? "NO" : "YES") << "\n";
	}
}
//맨 마지막이 yes임