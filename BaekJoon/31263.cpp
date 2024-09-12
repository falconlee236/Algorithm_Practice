#include <iostream>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, cnt = 0; cin >> n;
	string s, tmp; cin >> s;
	for(int i = n - 1; i >= 0; i--){
		tmp = s[i] + tmp;
		if (tmp.size() == 3){
			int num = stoi(tmp);
			if ((num > 641 && tmp[1] != '0') || (num < 100 && num > 9)) i++;
			else if ((num > 641 && tmp[1] == '0') || num < 10) i += 2;
			cnt++;
			tmp.clear();
		}
	}
	cout << (tmp.empty() ? cnt : cnt + 1);
}