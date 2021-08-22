/*1644*/
/*Got it!*/
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    bool prime[4000001];
    fill(prime, prime + 4000001, true);
    prime[1] = false; prime[0] = false;
    for(int i = 2; i * i <= 4000001; i++){
        if(!prime[i]) continue;
        for(int j = i + i; j <= 4000001; j += i){
            prime[j] = false;
        }
    }
    
    int n; scanf("%d", &n);
    int ans = 0, start = 2, end = 2, sum = 0;
    while(end <= n){
        if(sum < n){
            int prev = end;
            while(!prime[++end]);
            sum += prev;
        }
        else{
            int prev = start;
            if(sum == n) ans++;
            while(!prime[++start]);
            sum -= prev;
        }
    }
    printf("%d", prime[n] ? ans + 1 : ans);
    return 0;
}