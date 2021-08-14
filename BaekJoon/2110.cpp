/*2110*/
/*Cheating*/
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, m; scanf("%d %d", &n, &m);
    int home[200001] = {};
    for(int i = 0; i < n; i++) scanf("%d", &home[i]);
    sort(home, home + n);
    
    int start = 1, end = home[n - 1] - home[0], ans = 0;
    while(start <= end){
        int mid = (start + end) / 2;
        int before = 0;
        int res = 1;
        for(int i = 1; i < n; i++){
            if(home[i] - home[before] >= mid){
                before = i;
                res++;
            }
        }
        if(res < m) end = mid - 1;
        else{
            ans = mid;
            start = mid + 1;
        }
    }
    printf("%d", ans);
}