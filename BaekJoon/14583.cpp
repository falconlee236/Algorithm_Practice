#include <iostream>
#include <cmath>
using namespace std;
int main(){
    double h, v; cin >> h >> v;
    double d = sqrt(h * h + v * v), a = v * (h / (h + d)), b = v * (d / (h + d)), c = sqrt(a * a + h * h), k = (h * b) / c;
    cout << fixed;
    cout.precision(2);
    cout << c / 2 << " " << k;
}