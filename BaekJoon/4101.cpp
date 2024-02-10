#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    while (1){
        int a, b; cin >> a >> b;
        if (a == 0 && b == 0) break;
        cout << (a > b ? "Yes" : "No") << "\n";
    }
    return 0;
}
