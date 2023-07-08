#include <iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int a, b; cin >> a >> b;
    if ((a == 1 && b == 2) ||
        (a == 2 && b == 3) ||
        (a == 4 && b == 5) ||
        (a == 5 && b == 6) ||
        (a == 7 && b == 8) ||
        (a == 8 && b == 9))
        cout << "Yes";
    else cout << "No";
}