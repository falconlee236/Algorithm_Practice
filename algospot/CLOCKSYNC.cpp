#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> button = {
    {0, 1, 2},
    {3, 7, 9, 11},
    {4, 10, 14, 15},
    {0, 4, 5, 6, 7},
    {6, 7, 8, 10, 12},
    {0, 2, 14, 15},
    {3, 14, 15},
    {4, 5, 7, 14, 15},
    {1, 2, 3, 4, 5},
    {3, 4, 5, 9, 13}
};

int clk[16], ans;

void push(int num, int cnt, bool flag){
    for(int i = 0; i < cnt; i++){
        for(int j = 0; j < button[num].size(); j++){
            int idx = button[num][j];
            clk[idx] += (flag ? 3 : -3);
            if(clk[idx] == 15) clk[idx] = 3;
            if(clk[idx] == 0) clk[idx] = 12;
        }        
    }
}

void answer(int num, int cnt){
    if(num == 10){
        for(int i = 0; i < 16; i++) if(clk[i] != 12) return;
        ans = min(ans, cnt);
        return;
    }
    for(int i = 0; i < 4; i++){
        push(num, i, true);
        answer(num + 1, cnt + i);
        push(num, i, false);
    }
}

int main() {
    int t; cin >> t;
    while(t--){
        for(int i = 0; i < 16; i++) cin >> clk[i];
        ans = 987654321;
        answer(0, 0);
        cout << (ans == 987654321 ? -1 : ans) << "\n";
    }
	return 0;
}
