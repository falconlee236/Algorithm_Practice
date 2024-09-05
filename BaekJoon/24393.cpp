#include <iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    string s = "1000000000000000000000000000";
    while (T--){
        int res = 0, num, left_cnt = 0, right_cnt = 0;
        string left = s.substr(0, 13), right = s.substr(13), tmp;
        for (int i = 0; res != 27; i++){
            cin >> num;
            res += num;
            if (i % 2 == 0){
                tmp += right.substr(right_cnt, num);
                right_cnt += num;
            } else {
                tmp += left.substr(left_cnt, num);
                left_cnt += num;
            }
        }
        s = tmp;
    }
    cout << s.find("1") + 1;
}