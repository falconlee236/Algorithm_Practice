#include <iostream>
#include <string>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    string s; cin >> s;
    for(int i = 0; i < n; i++){
        cout << s[i] << s[i];
    }
    return 0;
}