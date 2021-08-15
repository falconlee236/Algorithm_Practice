/*2875*/
/*Got it!*/
#include <iostream>
using namespace std;

int main(){
    int n, m, k; scanf("%d %d %d", &n, &m, &k);
    int ans = 0;
    for(int i = 0; i <= k; i++){
        int a = n - i, b = m - (k - i);
        ans = max(ans, a / 2 > b ? b : a / 2);
    }
    printf("%d", ans);
    return 0;
}