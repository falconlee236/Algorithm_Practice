#include <iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, h, num; cin >> n >> h;
    for(int i = 1; i <= n; i++){
        cin >> num;
        h -= num;
        if (h <= 0){
            cout << i;
            return 0;
        }
    }
    cout << -1;
}