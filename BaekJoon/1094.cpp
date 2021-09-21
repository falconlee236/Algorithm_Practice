/*1094*/
/*Got it!*/
/*07:38*/
#include <iostream>
using namespace std;

int solve(int x){
    if(x == 0) return 0;
    return x % 2 + solve(x / 2);
}

int main(){
    int n; cin >> n;
    cout << solve(n);
}