#include <iostream>
#include <string>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    int n; cin >> n;
    cout << s[n - 1];
}