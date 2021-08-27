/*1920*/
/*Got it!*/
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int arr[100001];
    for(int i = 0; i < n; i++) cin >> arr[i];
    int t; cin >> t;
    sort(arr, arr + n);
    while(t--){
        int num; cin >> num;
        int left = 0, right = n - 1;
        bool flag = false;
        if(num > arr[n - 1] || num < arr[0]) left = right + 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(arr[mid] < num) left = mid + 1;
            else if (arr[mid] > num) right = mid - 1;
            else{
                flag = true;
                break;
            }
        }
        cout << (flag ? 1 : 0) << "\n";
    }
	return 0;
}