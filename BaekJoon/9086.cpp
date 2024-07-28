#include <iostream>
using namespace std;
int main(){
    int T; cin >> T;
    while (T--){
        string str; cin >> str;
        cout << str.front() << str.back() << "\n";
    }
}