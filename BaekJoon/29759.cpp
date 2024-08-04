#include <iostream>
#define MAX 1000010
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, k = 2; cin >> n;
    char arr[MAX] = {0, };
    for(int i = 2; i * i < MAX; i++){
        if (arr[i]) continue;
        for(int j = i + i; j < MAX; j+=i) arr[j] = 1;
    }
    int ans[n * n][n * n];
    for(int i = 0; i < n * n; i++){
        for(int j = 0; j < n * n; j++) {
            cin >> ans[i][j];
            for(int l = 1; l * l <= ans[i][j]; l++){
                if (ans[i][j] % l == 0){
                    arr[l] = 1;
                    arr[ans[i][j] / l] = 1;
                }
            }
            arr[ans[i][j]] = 1;
        }
    }
    for(int i = 0; i < n * n; i++){
        for(int j = 0; j < n * n; j++) {
            if (ans[i][j]) cout << ans[i][j] << " ";
            else {
                while(arr[k]) k++;
                arr[k] = 1;
                cout << k << " ";
            }
        }
        cout << "\n";
    }
}