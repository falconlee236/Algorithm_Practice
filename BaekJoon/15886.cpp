#include <iostream>
#include <string>
using namespace std;
int main(){
    int n; cin >> n;
    string s; cin >> s;
    int res = 1;
    for(int i = 0; i < n - 1; i++){
        if (s[i] == 'W' && s[i + 1] == 'E') res++;
    }
    cout << res;
}
