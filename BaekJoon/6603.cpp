/*6603*/
/*Got it!*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int k, arr[13];
vector<int> v;

void func(int pos, int cnt){
    if(cnt == 6){
        for(int i = 0; i < 6; i++) printf("%d ", v[i]);
        printf("\n");
        return;
    }
    for(int i = pos; i < k; i++){
        v.push_back(arr[i]);
        func(i + 1, cnt + 1);
        v.pop_back();
    }
}

int main(){
    while(1){
        scanf("%d", &k);
        if(!k) return 0;
        for(int i = 0; i < k; i++) scanf("%d", &arr[i]);
        func(0, 0);
        printf("\n");
        fill(arr, arr + k, 0);
    }
}