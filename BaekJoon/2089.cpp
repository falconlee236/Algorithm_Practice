/*2089*/
/*Got it!*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n; scanf("%d", &n);
    vector<int> v;
    while(n != 0 && n != 1){
        if(n == -1){
            n = 1;
            v.push_back(1);
            continue;
        }
        if(n < 0 && n % 2 != 0){
            n = n / -2 + 1;
            v.push_back(1);
        }
        else{
            v.push_back(n % -2);
            n /= -2;
        }
    }
    v.push_back(n);
    reverse(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++) printf("%d", v[i]);
    return 0;
}