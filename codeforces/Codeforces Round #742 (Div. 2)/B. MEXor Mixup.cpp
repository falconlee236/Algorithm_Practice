/*00:20*/
#include <cstdio>

int dp[300001];

int main(){
    for(int i = 1; i <= 300000; i++) dp[i] = (dp[i - 1] ^ i);
    int t; scanf("%d", &t);
    while(t--){
        int a, b; scanf("%d %d", &a, &b);
        int k = dp[a - 1];
        if(k == b) printf("%d\n", a);
        else{
            if((k ^ b) != a) printf("%d\n", a + 1);
            else printf("%d\n", a + 2);
        }
    }
    return 0;
}
