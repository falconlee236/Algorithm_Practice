#include <iostream>
#include <cmath>
using namespace std;
int main(){
    double d1, d2, d3; cin >> d1 >> d2 >> d3;
    double a = (d1 + d2 - d3) / 2;
    double c = d2 - a;
    double b = d3 - c;
    if (a <= 0 || b <= 0 || c <= 0) cout << -1;
    else{
        cout << 1 << "\n";
        cout << fixed;
        cout.precision(1);
        cout << ceil(a * 10) / 10 << " " << ceil(b * 10) / 10 << " " << ceil(c * 10) / 10;
    }
}
/*
a + b == d1
a + c == d2
b + c == d3

a - c = d1 - d3
a + c = d2
2a = d1 + d2 - d3
a = (d1 + d2 - d3) / 2
c = d2 - a
b = d3 - c
*/