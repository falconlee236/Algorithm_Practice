#include <iostream>
#include <stack>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	for (int i = 1;; i++){
		string s; cin >> s;
		int cnt = 0;
		if (s.front() == '-') break;
		stack<char> stk;
		for(char c: s){
			if (c == '{') stk.push(c);
			else if (stk.size() && stk.top() == '{') stk.pop();
			else stk.push('{'), cnt++;
		}
		cout << i << ". " << cnt + stk.size() / 2 << "\n";
	}
}