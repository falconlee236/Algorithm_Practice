#include <iostream>
#include <deque>
#include <string>
using namespace std;
using psi = pair<string, int>;
int main(){
	int n; cin >> n;
	deque<psi> dq;
	for(int i = 0; i < n; i++){
		string s; cin >> s;
		int num; cin >> num;
		dq.push_back({s, num});
	}
	while (dq.size() > 1){
		psi tmp = dq.front();
		dq.pop_front();
		tmp.second--;
		while (tmp.second--){
			dq.push_back(dq.front());
			dq.pop_front();
		}
		dq.pop_front();
	}
	cout << dq.front().first;
}

/*
e
c
b
*/