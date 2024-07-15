#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    string str, ans;
    int cnt[26] = {0, }, n, total_cnt = 0;
    cin >> n >> str;
    for(char c : str){
        if (!cnt[c - 'a']) ans += c;
        else total_cnt++;
        cnt[c - 'a']++;
    }
    ans = to_string(n + 1906) + ans + to_string(total_cnt + 4);
    reverse(ans.begin(), ans.end());
    cout << "smupc_" + ans;
}