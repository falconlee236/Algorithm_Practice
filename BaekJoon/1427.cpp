#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    sort(s.begin(), s.end(), greater<>());
    cout << s;
    return 0;
}
