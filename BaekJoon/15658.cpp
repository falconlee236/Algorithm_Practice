#include <iostream>
using namespace std;
int n, arr[12], oper[4], mn = 1000000000, mx = -1000000000;
void solve(int idx, int res){
	if (idx == n){
		mn = min(mn, res), mx = max(mx, res);
		return;
	}
	if (oper[0] > 0) oper[0]--, solve(idx + 1, res + arr[idx]), oper[0]++;
	if (oper[1] > 0) oper[1]--, solve(idx + 1, res - arr[idx]), oper[1]++;
	if (oper[2] > 0) oper[2]--, solve(idx + 1, res * arr[idx]), oper[2]++;
	if (oper[3] > 0) oper[3]--, solve(idx + 1, res / arr[idx]), oper[3]++;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i];
	for(int &x : oper) cin >> x;
	solve(1, arr[0]);
	cout << mx << "\n" << mn;
}