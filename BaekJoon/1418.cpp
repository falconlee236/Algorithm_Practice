#include <iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, k, ans = 0; cin >> n >> k;
    for(int num = 1; num <= n; num++){
        int tmp = num, num_factor = 1;
        for(int i = 2; i * i <= num; i++){
            while (tmp % i == 0){ //소인수분해
                num_factor = i;
                tmp /= i;
            }
        }
        if (tmp > 1) num_factor = tmp;
        if (num_factor <= k) ans++;
    }
    cout << ans;
}