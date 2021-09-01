#include <iostream>
using namespace std;

int house[20][20];
int dp[20][20][3];

int main() {
	int n; cin >> n;
	for(int i = 1; i <= n; i++){
	    for(int j = 1; j <= n; j++) cin >> house[i][j];
	}
	
	dp[1][2][1] = 1;
	for(int i = 1; i <= n; i++){
	    for(int j = 3; j <= n; j++){
	        if(house[i][j] == 1){
	            continue;
	        }
	        if(house[i][j - 1] == 1){
	            dp[i][j][2] = dp[i - 1][j][1] + dp[i - 1][j][2];
	        }
	        else if(house[i - 1][j] == 1){
	            dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][1];
	        }
	        else{
	            dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][1];
                dp[i][j][1] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
                dp[i][j][2] = dp[i - 1][j][1] + dp[i - 1][j][2];
	        }
            
	    }
	}
	

	cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
	return 0;
}
