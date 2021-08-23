/*1261*/
/*Got it!*/
#include <iostream>
#include <deque>
#include <tuple>
#include <string>
using namespace std;

int arr[100][100];
bool visit[100][100];

int main() {
	int m, n; cin >> m >> n;
	getchar();
	for(int i = 0; i < n; i++){
	    string str; getline(cin, str);
	    for(int j = 0; j < m; j++) arr[i][j] = str[j] - '0';
	}
	
	deque<tuple<int, int, int>> dq;
	dq.push_back(make_tuple(0, 0, 0));
	visit[0][0] = true;
	int pos[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	
	while(!dq.empty()){
	    int x = get<0>(dq.front());
	    int y = get<1>(dq.front());
	    int cnt = get<2>(dq.front());
	    if(x == n - 1 && y == m - 1){
	        printf("%d", cnt);
	        return 0;
	    }
	    dq.pop_front();
	    for(int i = 0; i < 4; i++){
	        int nx = x + pos[i][0];
	        int ny = y + pos[i][1];
	        if(0 <= nx && nx < n && 0 <= ny && ny < m){
	            if(!visit[nx][ny]){
    	            if(arr[nx][ny]) dq.push_back(make_tuple(nx, ny, cnt + 1));
    	            else dq.push_front(make_tuple(nx, ny, cnt));
    	            visit[nx][ny] = true;
    	        }
	        }
	    }
	}
	return 0;
}
