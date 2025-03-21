#include <iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    if (s == "SONGDO") cout << "HIGHSCHOOL";
    else if (s == "CODE") cout << "MASTER";
    else if (s == "2023") cout << "0611";
    else cout << "CONTEST";
}