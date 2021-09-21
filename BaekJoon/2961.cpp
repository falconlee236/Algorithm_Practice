#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    int sour[11], bitter[11];
    int bit = (1 << n) - 1;
    for(int i = 0; i < n; i++) cin >> sour[i] >> bitter[i];
    int ans = 987654321;
    for(int i = bit; i; i = (bit & (i - 1))){
        int so = 1, bi = 0;
        for(int j = 0; j < 10; j++){
            if(i & (1 << j)){
                so *= sour[j];
                bi += bitter[j];
            }
        }
        ans = min(ans, abs(bi - so));
    }
    cout << ans;
}