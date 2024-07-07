#include <iostream>
using namespace std;
int main(void){
    cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    int T; cin >> T;
    while (T--){
        int n; cin >> n;
        int w = 0, b = 0;
        string str1, str2;
        cin >> str1 >> str2;
        for(int i = 0; i < n; i++){
            if (str1[i] == str2[i]) continue;
            if (str1[i] == 'W') w++;
            else b++;
        }
        cout << max(w, b) << "\n";
    }
}