#include <iostream>
#include <stack>
#include <string>
#include <algorithm>


using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    int cnt = 0;
    stack<char> stk;
    for(int i = 0; i < n; i++){
        char c = s[i];
        if(c == '('){
            cnt++;
            stk.push(c);
        }
        else if(c == ')' && cnt > 0){
            while (stk.top() != '(') stk.pop();
            stk.pop();
            cnt--;
        }
        else stk.push(c);
    }
    string res = "";
    while (stk.size()){
        res += stk.top();
        stk.pop();
    }
    reverse(res.begin(), res.end());
    cout << res;
}