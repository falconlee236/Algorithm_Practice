#include <iostream>
#include <cstring>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    string a, b; cin >> a >> b;
    cout << (strstr(a.c_str(), b.c_str()) ? 1 : 0);
}