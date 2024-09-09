#include <iostream>
#include <deque>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    deque<int> deq;
    int n, k, m; cin >> n >> k >> m;
    bool flag = true;
    for(int i = 1; i <= n; i++) deq.push_back(i);
    for(int i = 1; deq.size(); i++){
        for(int j = 0; j < k - 1 && flag; j++){
            deq.push_back(deq.front());
            deq.pop_front();
        }
        for(int j = 0; j < k - 1 && !flag; j++){
            deq.push_front(deq.back());
            deq.pop_back();
        }
        if (flag){
            cout << deq.front() << "\n";
            deq.pop_front();
        } else {
            cout << deq.back() << "\n";
            deq.pop_back();
        }
        if (i % m == 0) flag = !flag;
    }
}