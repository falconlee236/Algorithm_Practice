/*1850*/
/*Got it!*/
#include <iostream>
#include <algorithm>
using namespace std;

int gcd(long long x, long long y){
    if(y == 0) return x;
    return gcd(y, x % y);
}

int main(){
    long long a, b; scanf("%lld %lld", &a, &b);
    int res = gcd(max(a, b), min(a, b));
    for(int i = 0; i < res; i++) cout << 1;
    return 0;
}