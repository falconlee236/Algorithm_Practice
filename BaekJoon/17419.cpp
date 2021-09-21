/*17419*/
/*Got it!*/
/*10:31*/
#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    string str; cin >> str;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(str[i] == '1') ans++;
    }
    cout << ans;
    return 0;
}