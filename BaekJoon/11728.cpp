/*11728*/
/*Got it!*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n, m; scanf("%d %d", &n, &m);
    vector<int> u, v;
    while(n--){
        int a; scanf("%d", &a);
        u.push_back(a);
    }
    while(m--){
        int b; scanf("%d", &b);
        v.push_back(b);
    }
    u.insert(u.end(), v.begin(), v.end());
    sort(u.begin(), u.end());
    for(unsigned int i = 0; i < u.size(); i++) printf("%d ", u[i]);
    return 0;
}