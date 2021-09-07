/*2206*/
/*Cheating*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <string>
using namespace std;

char arr[1001][1001];
bool visit[1001][1001][2];

int main(){
	int n, m; cin >> n >> m;
	for(int i = 0; i < n; i++){
	    cin >> arr[i];
	}
	int pos[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    queue<tuple<int, int, int, int>> q;
    q.emplace(0, 0, 1, 0);
    visit[0][0][0] = true;
    while(!q.empty()){
	    int row = get<0>(q.front());
	    int col = get<1>(q.front());
	    int dist = get<2>(q.front());
	    int chance = get<3>(q.front());
	    if(row == n - 1 && col == m - 1){
	        cout << dist;
	        return 0;
	    }
	    q.pop();
	    for(int i = 0; i < 4; i++){
	        int nrow = row + pos[i][0];
	        int ncol = col + pos[i][1];
	        if(0 <= nrow && nrow < n && 0 <= ncol && ncol < m){
                if(arr[nrow][ncol] == '1' && chance == 0){
                    visit[nrow][ncol][chance + 1] = true;
                    q.emplace(nrow, ncol, dist + 1, chance + 1);
                }
                else if(arr[nrow][ncol] == '0' && !visit[nrow][ncol][chance]){
                    visit[nrow][ncol][chance] = true;
                    q.emplace(nrow, ncol, dist + 1, chance);
                }
	        }
	    }
    }
	cout << -1;
	return 0;
}
