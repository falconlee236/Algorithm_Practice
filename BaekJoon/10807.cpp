#include <iostream>

using namespace std;

int main(void){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int t; cin >> t;
    int res = 0;
    for(int i = 0; i < n; i++){
        if (a[i] == t) res++;
    }
    cout << res << "\n";
}
