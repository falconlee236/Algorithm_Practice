/*10844*/
#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    long long m[101][10];
    
    for(int i = 1; i < 10; i++) m[1][i] = 1;
    
    for(int i = 2; i < 101; i++){
        for(int j = 0; j < 10; j++){
            if(j == 0) m[i][j] = m[i - 1][1];
            else if(j == 9) m[i][j] = m[i - 1][8];
            else m[i][j] = m[i - 1][j - 1] + m[i - 1][j + 1];
            
            m[i][j] %= 1000000000;
        }
    }
    
    long long res = 0;
    for(int i = 0; i < 10; i++) res += m[n][i];
    cout << res % 1000000000;
    return 0;
}