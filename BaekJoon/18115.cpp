#include <iostream>
#include <list>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++) cin >> arr[i];
	list<int> lst;
	int num = 1;
	for(int i = n - 1; i >= 0; i--){
		if (arr[i] == 1) lst.push_front(num);
		else if (arr[i] == 3) lst.push_back(num);
		else lst.insert(++lst.begin(), num);
		num++;
	}
	for(auto x : lst) cout << x << " ";
}