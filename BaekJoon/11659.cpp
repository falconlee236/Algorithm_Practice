#include <iostream>
using namespace std;
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    int a[n + 1] = {0, };
    for(int i = 1; i <= n; i++){
        int num; cin >> num;
        a[i] = a[i - 1] + num;
    }
    while (m--){
        int x, y; cin >> x >> y;
        cout << a[y] - a[x - 1] << "\n";
    }
}