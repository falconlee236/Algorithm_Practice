/*2186*/
/*Cheating*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

char arr[100][100];
int dp[100][100][100];
int n, m, k;
string input;

int pos[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int dfs(int row, int col, int idx){
    if(dp[row][col][idx] != -1) return dp[row][col][idx];
    if(idx >= input.size()) return 1;
    
    dp[row][col][idx] = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 1; j <= k; j++){
            int nrow = row + pos[i][0] * j;
            int ncol = col + pos[i][1] * j;
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                if(arr[nrow][ncol] == input[idx]){
                    dp[row][col][idx] += dfs(nrow, ncol, idx + 1);
                }
            }
        }
    }
    return dp[row][col][idx];
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	getchar();
	memset(dp, -1, sizeof(dp));
	for(int i = 0; i < n; i++){
	    string str; getline(cin, str);
	    for(int j = 0; j < m; j++){
	        arr[i][j] = str[j];
	    }
	}
	
	getline(cin, input);
	
	int res = 0;
	for(int i = 0; i < n; i++){
	    for(int j = 0; j < m; j++){
	        if(arr[i][j] == input[0]) res += dfs(i, j, 1);
	    }
	}
	
	printf("%d", res);
	return 0;
}
