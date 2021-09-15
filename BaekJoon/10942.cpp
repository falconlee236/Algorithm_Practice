/*10942*/
/*Got it!*/
#include <iostream>
using namespace std;

int dp[2002][2002];
int arr[2002];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> arr[i];
	for(int i = 1; i <= n; i++) dp[i][i] = true;
	for(int i = 1; i < n; i++){
	    if(arr[i] == arr[i + 1]) dp[i][i + 1] = true;
	}
	
	for(int i = 1; i <= n; i++){
	    for(int j = 1;; j++){
	        if(i - j < 0 || i + j > n) break;
            dp[i - j][i + j] = dp[i - j + 1][i + j - 1] * (arr[i - j] == arr[i + j]);
	    }
	    
	    for(int j = 1;; j++){
	        if(i - j < 0 || i + 1 + j > n) break;
            dp[i - j][i + 1 + j] = dp[i - j + 1][i + 1 + j - 1] * (arr[i - j] == arr[i + 1 + j]);
	    }
	    
	}
    int m; cin >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        cout << dp[a][b] << "\n";
    }
	return 0;
}
