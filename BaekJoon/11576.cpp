/*11576*/
/*Got it!*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int a, b, m; scanf("%d %d %d", &a, &b, &m);
    int res = 0;
    for(int i = m - 1; i >= 0; i--){
        int p = pow(a, i);
        int n; scanf("%d", &n);
        res += (n * p);
    }
    vector<int> v;
    while(res > 1){
        v.push_back(res % b);
        res /= b;
    }
    if(res == 1) v.push_back(res);
    reverse(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        printf("%d ", v[i]);
    }
    return 0;
}