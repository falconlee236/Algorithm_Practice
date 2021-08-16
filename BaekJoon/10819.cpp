/*10819*/
/*Got i1*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(){
    int n; scanf("%d", &n);
    vector<int> v;
    for(int i = 0; i < n; i++){
        int n; scanf("%d", &n);
        v.push_back(n);
    }
    sort(v.begin(), v.end());
    int ans = 0;
    do{
        int res = 0;
        for(int i = 1; i < n; i++) res += abs(v[i] - v[i - 1]);
        ans = max(ans, res);
    }while(next_permutation(v.begin(), v.end()));
    printf("%d", ans);
    return 0;
}