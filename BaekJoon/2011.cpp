/*2011*/
/*Got it!*/
#include <iostream>
#include <string>
#include <algorithm>
#define DIV 1000000
using namespace std;

int main(){
    string str; cin >> str;
    int len = str.size();
    int arr[5001] = {};
    for(int i = 1; i <= len; i++) arr[i] = str[i - 1] - '0';
    if(count(arr + 1, arr + len + 1, 0) == len){
        cout << 0;
        return 0;
    }
    long long dp[5001] = {};
    dp[0] = 1;
    dp[1] = arr[len] == 0 ? 0 : 1;
    for(int i = 2; i <= len; i++){
        int idx = i - 2;
        int check = 10 * arr[len - (idx + 1)] + arr[len - idx];
        if(check < 27 && check > 0) {
            if(arr[len - (idx + 1)] > 0) dp[i] += dp[i - 2];
        }
        if(arr[len - (idx + 1)] > 0) dp[i] += dp[i - 1];
        dp[i] %= DIV;
    }
    cout << dp[len] % DIV;
    return 0;
}
