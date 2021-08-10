/*2331*/
/*Got it!*/
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int a, p; scanf("%d %d", &a, &p);
    vector<int> v;
    v.push_back(a);
    for(int i = 1;; i++){
        int cal = 0;
        int back = v.back();
        while(back > 0){
            cal += pow((back % 10), p);
            back /= 10;
        }
        v.push_back(cal);
        auto p = find(v.begin(), v.end() - 1, cal);
        if(p != v.end() - 1){
            printf("%d", p - v.begin());
            break;
        }
    }
    return 0;
}