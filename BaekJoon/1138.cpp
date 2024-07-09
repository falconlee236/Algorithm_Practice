#include <iostream>
using namespace std;
int main(void){
    int n; cin >> n;
    int a[n] = {0, };
    for(int i = 0; i < n; i++){
        int num; cin >> num;
        for(int j = 0; j < n; j++){
            if (num <= 0 && a[j] == 0){
                a[j] = i + 1;
                break;   
            }
            if (a[j] == 0) num--;
        }
    }
    for(int x : a) cout << x << " ";
}