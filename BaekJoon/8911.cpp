#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int main(void){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while(n--){
		string s; cin >> s;
		vector<int> arr_x, arr_y;
		arr_x.push_back(0);
		arr_y.push_back(0);
		int x = 0, y = 0, idx = 0;
		for(int i = 0; s[i]; i++){
			if (s[i] == 'F'){
				x += dx[idx];
				y += dy[idx];
			}
			else if (s[i] == 'B'){
				x -= dx[idx];
				y -= dy[idx];
			}
			else if (s[i] == 'L') idx = (idx + 1) % 4;
			else{
				if (idx == 0) idx = 3;
				else idx--;
			}
			arr_x.push_back(x);
			arr_y.push_back(y);
		}
		auto res_x = minmax_element(arr_x.begin(), arr_x.end());
		auto res_y = minmax_element(arr_y.begin(), arr_y.end());
		cout << (*res_x.second - *res_x.first) * (*res_y.second - *res_y.first) << "\n";
	}
}