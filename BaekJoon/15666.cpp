/*15666*/
/*Got it!*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, arr[9];
vector<int> v;
bool visit[9];

void func(int pos, int cnt){
    if(cnt == m){
        for(int x : v) cout << x << " ";
        cout << "\n";
        return;
    }
    int prev = -1;
    for(int i = pos; i < n; i++){
        if(i > 0) prev = arr[i - 1];
        if(prev != arr[i]){
            v.push_back(arr[i]);
            func(i, cnt + 1);
            v.pop_back();
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    func(0, 0);
	return 0;
}
