#include <iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        double x; cin >> x;
        string s; cin >> s;
        cout << fixed;
        cout.precision(4);
        if (s == "kg") cout << x * 2.2046 << " lb\n";
        else if (s == "l") cout << x * 0.2642 << " g\n";
        else if (s == "lb") cout << x * 0.4536 << " kg\n";
        else cout << x * 3.7854 << " l\n";
    }
}