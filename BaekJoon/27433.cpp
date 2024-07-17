#include <iostream>
using namespace std;
int main(void){
    long long n, ans = 1; cin >> n;
    while (n) ans *= n--;
    cout << ans;
}