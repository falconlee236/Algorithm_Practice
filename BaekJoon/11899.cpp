#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
    stack<char> stk;
    string s; cin >> s;
    for(auto x : s){
        if (stk.size() && stk.top() == '(' && x == ')') stk.pop();
        else stk.push(x);
    }
    cout << stk.size();
    return 0;
}
