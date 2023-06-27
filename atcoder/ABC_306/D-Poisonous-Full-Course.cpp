#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    long long res = 0, tmp = 0;
    for(int i = 0; i < n; i++){
        int isok; long long taste; cin >> isok >> taste;
        if (isok) tmp = max(tmp, taste);
        else{
            if (taste + tmp >= 0 || taste >= 0)
                res += (taste + tmp >= taste ? taste + tmp : taste);
            tmp = 0;
        }
    }
    if (tmp >= 0) cout << res + tmp;
    else cout << res;
}