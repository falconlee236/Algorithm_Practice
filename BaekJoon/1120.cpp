/*1120*/
/*Got it!*/
/*14:02*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string a, b; cin >> a >> b;
    int ans = 987654321;
    for(int k = 0; k <= b.size() - a.size(); k++){
        int tmp = 0;
        for(int i = 0; i < a.size(); i++){
            if(a[i] != b[i + k]) tmp++;
        }
        ans = min(ans, tmp);
    }
    cout << ans;
    return 0;
}