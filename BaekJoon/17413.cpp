#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; getline(cin, s);
    stack<char> stk;
    for(int i = 0; i < (int)s.length();){
        if (s[i] == '<'){
            while (s[i] != '>')
                cout << s[i++];
            continue;
        }
        if (isalnum(s[i])){
            while (isalnum(s[i]))
                stk.push(s[i++]);
            while (stk.size()){
                cout << stk.top();
                stk.pop();
            }
        } else cout << s[i++];
    }
    return 0;
}