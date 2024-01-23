#include <iostream>
#include <stack>
using namespace std;

int main(void){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    stack<int> stk;
    int idx = 1;
    for(int i = 0; i < n; i++){
        if (stk.size() && stk.top() == idx){
            stk.pop();
            idx++;
            i--;
        }
        else if (arr[i] == idx) idx++;
        else stk.push(arr[i]);
    }
    while (stk.size()){
        if (stk.top() == idx){
            idx++;
            stk.pop();
        }
        else{
            cout << "Sad" << "\n";
            return 0;
        }
    }
    cout << "Nice" << "\n";
    return 0;
}