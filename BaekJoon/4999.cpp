#include <iostream>
#include <string>
using namespace std;
int main() {
    string a, b; cin >> a >> b;
    cout << (a.find(b) == string::npos ? "no\n" : "go\n");
}
