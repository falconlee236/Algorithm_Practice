/*10824*/
/*Got it!*?*/
#include <iostream>
#include <string>
using namespace std;

int main(){
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << stol(a + b) + stol(c + d);
    return 0;
}