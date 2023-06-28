#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<string> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (i == j) continue;
            string tmp = v[i] + v[j];
            bool flag = true;
            for(int k = 0; k < tmp.length() / 2; k++){
                if (tmp[k] != tmp[tmp.length() - 1 - k]){
                    flag = false;
                    break;
                }
            }
            if (flag){
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";
}