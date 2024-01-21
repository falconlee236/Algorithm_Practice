#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;

int main(void){
	int n; cin >> n;
	int arr[n];
	iota(arr, arr + n, 1);
	do{
		for(auto x : arr) cout << x << " ";
		cout << "\n";
	} while(next_permutation(arr, arr + n));
}