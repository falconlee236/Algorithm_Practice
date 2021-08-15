/*1517*/
/*Got it!*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[500000];
long long cnt = 0;
vector<int> v;

void merge_sort(int start, int end){
    if(start < end){
        int mid = (start + end) / 2;
        merge_sort(start, mid);
        merge_sort(mid + 1, end);
        
        int i = start, j = mid + 1, idx = start;
        while(i <= mid && j <= end){
            if(arr[i] > arr[j]){
                v[idx++] = arr[j++];
                cnt += (mid - i + 1);
            }
            else v[idx++] = arr[i++];
        }
        while(i <= mid) v[idx++] = arr[i++];
        while(j <= end) v[idx++] = arr[j++];
        
        for(int i = start; i <= end; i++){
            arr[i] = v[i];
        }
    }
}

int main(){
    int n; scanf("%d", &n);
    v = vector<int>(n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    merge_sort(0, n - 1);
    printf("%lld", cnt);
    return 0;
}