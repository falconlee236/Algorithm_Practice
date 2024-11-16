#include <iostream>
#include <stack>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	string s; cin >> s;
	stack<char> stk;
	for(char c : s){
		stk.push(c);
		if (stk.size() < 4) continue;
		while (stk.size() > 3){
			string tmp;
			for(int i = 0; i < 4; i++){
				tmp.push_back(stk.top());
				stk.pop();
			}
			if (tmp == "PAPP") stk.push('P');
			else {
				for(int i = tmp.length() - 1; i >= 0; i--) stk.push(tmp[i]);
				break;
			}
		}
	}
	cout << (stk.size() == 1 && stk.top() == 'P' ? "PPAP" : "NP");
}