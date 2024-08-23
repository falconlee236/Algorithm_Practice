#include <iostream>
#include <string>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s; getline(cin, s);
    int a = 0, b = 0;
    for(size_t i = 0; i + 3 < s.length(); i++){
        if (s[i] == ':' && s[i + 1] == '-') {
            if (s[i + 2] == ')') a++;
            else if (s[i + 2] == '(') b++;
        }
    }
    if (a == 0 && b == 0) cout << "none";
    else if (a == b) cout << "unsure";
    else if (a > b) cout << "happy";
    else cout << "sad";
}