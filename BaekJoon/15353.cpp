#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    string a, b, c; cin >> a >> b;
    if (a.length() < b.length()) swap(a, b);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    size_t i = 0, j = 0, add = 0;
    while (i < a.length() && j < b.length()){
        size_t tmp = (a[i++] - '0') + (b[j++] - '0') + add;
        add = tmp / 10;
        c += to_string(tmp % 10);
    }
    while (i < a.length()){
        size_t tmp = (a[i++] - '0') + add;
        add = tmp / 10;
        c += to_string(tmp % 10);
    }
    if (add) c += to_string(add);
    reverse(c.begin(), c.end());
    cout << c;
}