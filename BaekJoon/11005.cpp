/*11005*/
/*Got it!*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    long long n; scanf("%lld", &n);
    int b; scanf("%d", &b);
    vector<long long> v;
    while(n / b > 0){
        long long m = n % b;
        n /= b;
        v.push_back(m);
    }
    v.push_back(n);
    reverse(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        if(v[i] > 9) printf("%c", v[i] + 55);
        else printf("%d", v[i]);
    }
    return 0;
}