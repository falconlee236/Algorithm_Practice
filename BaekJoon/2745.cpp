/*2745*/
/*Got it!*/
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int main(){
    string n; cin >> n;
    reverse(n.begin(), n.end());
    int b; scanf("%d", &b);
    long long res = 0;
    for(int i = 0; n[i] != '\0'; i++){
        long long p = pow(b, i);
        if(n[i] > 57) res += ((n[i] - 55) * p);
        else res += ((n[i] - 48) * p);
    }
    printf("%lld", res);
    return 0;
}