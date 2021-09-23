#include <iostream>
#include <string>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string str[51];
        for(int i = 1; i <= n; i++){
            string pre(i, '(');
            string suf(i, ')');
            str[i] = pre + suf;
        }
        for(int i = 1; i <= n; i++){
            int a = i, b = n - i;
            cout << str[a] + str[b] << "\n";
        }
    }
}