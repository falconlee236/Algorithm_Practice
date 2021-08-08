/*2004*/
/*cheating*/
#include <iostream>
#include <algorithm>
using namespace std;

pair<long long, long long> count(long long num){
    long long a = 0, b = 0;
    for(long long i = 2; i <= num; i *= 2){
        a += (num / i);
    }
    for(long long i = 5; i <= num; i *= 5){
        b += (num / i);
    }
    return make_pair(a, b);
}

int main(){
    long long n, m; scanf("%lld %lld", &n, &m);
    pair<long long, long long> x, y, z;
    x = count(n);
    y = count(m);
    z = count(n - m);
    printf("%lld", min(x.first - y.first - z.first, x.second - y.second - z.second));
    return 0;
}