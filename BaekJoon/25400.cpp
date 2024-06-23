#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int cnt = 1, res = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if (x != cnt) res++;
        else cnt++;
    }
    cout << res;
}