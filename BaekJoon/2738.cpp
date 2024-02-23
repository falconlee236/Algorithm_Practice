#include <iostream>
using namespace std;
int main(void){
    cin.tie(0)->sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    int a[n][m], b[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> a[i][j];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) cin >> b[i][j];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) cout << a[i][j] + b[i][j] << " ";
        cout << "\n";
    }
}