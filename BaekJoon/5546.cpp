#include <iostream>
#define DIV 10000
int arr[101], a[101], aa[101], b[101], bb[101], c[101], cc[101];
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    while (k--){
        int a, b; cin >> a >> b;
        arr[a] = b;
    }
    if (arr[1] == 1) a[1] = 1;
    else if (arr[1] == 2) b[1] = 1;
    else if (arr[1] == 3) c[1] = 1;
    else a[1] = b[1] = c[1] = 1;
    for(int i = 2; i <= n; i++){
        if (arr[i] == 1){
            a[i] = (b[i - 1] + bb[i - 1] + c[i - 1] + cc[i - 1]) % DIV;
            aa[i] = a[i - 1];
        }
        else if (arr[i] == 2){
            b[i] = (a[i - 1] + aa[i - 1] + c[i - 1] + cc[i - 1]) % DIV;
            bb[i] = b[i - 1];
        }
        else if (arr[i] == 3){
            c[i] = (a[i - 1] + aa[i - 1] + b[i - 1] + bb[i - 1]) % DIV;
            cc[i] = c[i - 1];
        } else {
            a[i] = (b[i - 1] + bb[i - 1] + c[i - 1] + cc[i - 1]) % DIV;
            aa[i] = a[i - 1];
            b[i] = (a[i - 1] + aa[i - 1] + c[i - 1] + cc[i - 1]) % DIV;
            bb[i] = b[i - 1];
            c[i] = (a[i - 1] + aa[i - 1] + b[i - 1] + bb[i - 1]) % DIV;
            cc[i] = c[i - 1];
        }
    }
    cout << (a[n] + aa[n] + b[n] + bb[n] + c[n] + cc[n]) % DIV;
}