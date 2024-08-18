#include <iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    while (1){
        int a, b; cin >> a >> b;
        if (a == 0 && b == 0) break;
        if (b > a - b) b = a - b;
        long long x = 1;
        for(int i = 1; i <= b; i++) x = x * (a - i + 1) / i;
        cout << x << "\n";
    }
}