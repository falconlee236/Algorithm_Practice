/*9095*/
#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    int m[11] = {0, 1, 2, 4, };
    for(int i = 4; i < 12; i++){
        m[i] = m[i - 3] + m[i - 2] + m[i - 1];
    }
    while(t--){
        int n; cin >> n;
        cout << m[n] << "\n";
    }
    return 0;
}