#include <iostream>
using namespace std;
int arr[1000010];

int main(void){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> arr[i];
	int cnt = arr[1];
	int start = arr[1];
	for(int i = 1; i <= n; i++){
		if (arr[i] != start){
			start = arr[i];
			if (arr[i]) cnt++;
		}
	}
	while (m--){
		int type; cin >> type;
		if (type == 0) cout << cnt << "\n";
		else{
			int num; cin >> num;
			if (arr[num]) continue;
			arr[num] = 1;
			if (arr[num - 1] && arr[num + 1]) cnt--;
			else if (!arr[num - 1] && !arr[num + 1]) cnt++;
		}
	}
}