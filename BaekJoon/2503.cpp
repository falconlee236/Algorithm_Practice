#include <iostream>
#include <vector>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	vector<string> v;
	for(int i = 1; i < 10; i++){
		for(int j = 1; j < 10; j++){
			for(int k = 1; k < 10; k++){
				if (i != j && j != k && i != k)
					v.push_back(to_string(i * 100 + j * 10 + k));
			}
		}
	}
	while (T--){
		string str; int ball, strike;
		cin >> str >> strike >> ball;
		vector<string> tmp;
		for(string s : v){
			int b_cnt = 0, s_cnt = 0;
			for(int i = 0; i < 3; i++){
				for(int j = 0; j < 3; j++){
					if (s[i] == str[j] && i == j) s_cnt++;
					if (s[i] == str[j] && i != j) b_cnt++;
				}
			}
			if (b_cnt == ball && s_cnt == strike) tmp.push_back(s);
		}
		v = tmp;
	}
	cout << v.size();
}

/*
123
142

*/