/*2609*/
/*cheating*/
#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    int a, b; scanf("%d %d", &a, &b);
    int m = gcd(max(a, b), min(a, b));
    int n = a * b / m;
    printf("%d\n%d", m, n);
    return 0;
}