#include <iostream>
#include <stack>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, num; cin >> n;
    long long ans = 0;
    stack<int> stk;
    while(n--){
        cin >> num;
        while (stk.size() && stk.top() <= num) stk.pop();
        ans += stk.size();
        stk.push(num);
    }
    cout << ans;
}
/*
나를 볼 수 있는 빌딩은 자신보다 키가 큰 빌딩 뿐
*/