#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n, k; cin >> n >> k;
	vector<int> arr(n); for(int &x:arr){
		cin >> x;
		char c; cin >> c;
	}
	for(int i = 1; i <= k; i++){
		vector<int> tmp;
		for(size_t j = 1; j < arr.size(); j++) tmp.push_back(arr[j] - arr[j - 1]);
		arr = tmp;
	}
	for(size_t i = 0; i < arr.size() - 1; i++) cout << arr[i] << ",";
	cout << arr.back();
}