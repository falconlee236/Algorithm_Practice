/*12015*/
/*Cheating*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    int arr[1000001];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    vector<int> lis;
    for(int i = 0; i < n; i++){
        int cur = arr[i];
        if(lis.size() == 0 || lis.back() < cur) lis.push_back(cur);
        else{
            int idx = lower_bound(lis.begin(), lis.end(), cur) - lis.begin();
            lis[idx] = cur;
        }
    }
    cout << lis.size();
    return 0;
}