/*11660*/
/*Got it!*/
#include <iostream>
using namespace std;

int arr[1030][1030];
int dp[1030][1030];

int main() {
    int n, m; scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) scanf("%d", &arr[i][j]);
    }
    
    for(int i = 1; i <= n; i++){
        int tmp = arr[i][1];
        dp[i][1] = tmp;
        for(int j = 2; j <= n; j++){
            tmp += arr[i][j];
            dp[i][j] = tmp;
        }
    }
    
    while(m--){
        int x1, y1, x2, y2; scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        int ans = 0;
        for(int i = x1; i <= x2; i++) ans += dp[i][y2];
        if(y1 != 1) for(int i = x1; i <= x2; i++) ans -= dp[i][y1 - 1];
        printf("%d\n", ans);
    }
	return 0;
}
