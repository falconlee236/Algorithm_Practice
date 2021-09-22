#include <cstdio>
#include <vector>
using namespace std;

int arr[100001], sum[100001];
int n, k;

int solve1(){
    vector<long long> division(k);
    for(int i = 0; i < n + 1; i++) division[sum[i]]++;
    int ans = 0;
    for(int i = 0; i < k; i++){
        long long cnt = division[i];
        if(cnt >= 2){
            ans = (ans + (cnt * (cnt - 1) / 2)) % 20091101;
        }
    }
    return ans;
}

int solve2(){
    vector<int> ret(n + 1);
    vector<int> prev(k, -1);
    for(int i = 0; i < n + 1; i++){
        if(i > 0) ret[i] = ret[i - 1];
        else ret[i] = 0;
        
        int loc = prev[sum[i]];
        if(loc != -1) ret[i] = max(ret[i], ret[loc] + 1);
        prev[sum[i]] = i;
    }
    return ret.back();
}

int main(){
    int t; scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &k);
        for(int i = 1; i <= n; i++){
            scanf("%d", &arr[i]);
            sum[i] = sum[i - 1] + arr[i];
            sum[i] %= k;
        }
        printf("%d %d\n", solve1(), solve2());
    }
}