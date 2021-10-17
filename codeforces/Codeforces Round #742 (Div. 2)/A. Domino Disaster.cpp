/*00:06*/
#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        char arr[n];
        for(int i = 0; i < n; i++){
            char c; cin >> c;
            if(c == 'U') arr[i] = 'D';
            else if(c == 'D') arr[i] = 'U';
            else arr[i] = c;
        }
        for(int i = 0; i < n; i++) cout << arr[i];
        cout << "\n";
    }
    return 0;
}