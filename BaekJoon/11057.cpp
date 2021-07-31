/*11057*/
#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    int m[1001][10] = {};
    
    for(int i = 0; i < 10; i++) m[1][i] = 1;
    
    for(int i = 2; i <= n; i++){
        for(int j = 0; j < 10; j++){
            for(int k = j; k >= 0; k--){
                m[i][j] += m[i - 1][k];
            }
            m[i][j] %= 10007;
        }
    }
    
    int res = 0;
    for(int i = 0; i < 10; i++) res += (m[n][i] % 10007);
    cout << res % 10007;
    return 0;
}