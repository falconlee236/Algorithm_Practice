#include <iostream>
#include <string>
using namespace std;

int main(void){
    string s; cin >> s;
    int back = 0, ans = 0;
    for(int i = 0; i < s.length() - 1; i++){
        if (s[i] == '(' and s[i + 1] == '(') back++;
        else if (s[i] == ')' and s[i + 1] == ')') ans += back;
    }
    cout << ans;
}
//7분 49초