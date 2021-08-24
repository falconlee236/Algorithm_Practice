#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int arr[9];
bool visit[9];
vector<int> v;

void func(int cnt){
    if(cnt == m){
        for(int x : v) cout << x << " ";
        cout << "\n";
        return;
    }
    for(int i = 0; i < n; i++){
        if(!visit[i]){
            visit[i] = true;
            v.push_back(arr[i]);
            func(cnt + 1);
            v.pop_back();
            visit[i] = false;
        }
    }
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	func(0);
	return 0;
}
