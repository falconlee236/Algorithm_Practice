/*1934*/
/*Got it!*/
#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    int t; scanf("%d", &t);
    while(t--){
        int a, b; scanf("%d %d", &a, &b);
        printf("%d\n", a * b / gcd(max(a, b), min(a, b)));
    }
    return 0;
}