#include <iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0);
    unsigned long long res = 0, tmp = 1;
    for(long long i = 0; i < 64; i++){
        int n; cin >> n;
        res += n * (tmp << i);
    }
    cout << res;
    return 0;
}