#include <iostream>
using namespace std;
int main(){
    int T, num; cin >> T;
    for(int i = 1; i <= T; i++){
        cin >> num;
        cout << "Case #" << i << ": ";
        if (!num) cout << "INSOMNIA\n";
        else {
            int cnt[10] = {0, };
            for(int j = 1, tmp = num;; j++){
                string str = to_string(tmp);
                for(char c : str) cnt[c - '0']++;
                bool flag = true;
                for(int x : cnt){
                    if (x == 0) flag = false;
                }
                if (flag) {
                    cout << tmp << "\n";
                    break;
                }
                tmp = num * j;
            }
        }
    }
}