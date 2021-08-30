/*2292*/
/*Got it!*/
#include <iostream>
using namespace std;

int main(){
    long long n; cin >> n;
    long long tmp = 1;
    if(n == 1){
        cout << 1;
        return 0;
    }
    for(long long i = 1;; i++){
        tmp += (i * 6);
        long long left = tmp - (i * 6) + 1;
        long long right = tmp;
        if(left <= n && n <= right){
            cout << i + 1;
            return 0;
        }
    }
}