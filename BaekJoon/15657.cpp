#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, arr[9];
vector<int> v;

void func(int pos, int cnt){
    if(cnt == m){
        for(int x : v) cout << x << " ";
        cout << "\n";
        return;
    }
    for(int i = pos; i < n; i++){
        v.push_back(arr[i]);
        func(i, cnt + 1);
        v.pop_back();
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    func(0, 0);
	return 0;
}