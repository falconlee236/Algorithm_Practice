#include <iostream>
using namespace std;
int main(){
    long long n; cin >> n;
    for(long long i = 1; i * i <= 3 * n; i++){
        if (i * (i + 1) >= 2 * n) {
            cout << (i * (i + 1) == 2 * n ? i : i - 1);
            return 0;
        }
    }
}