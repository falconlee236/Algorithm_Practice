/*1182*/
/*Got it!*/
#include <iostream>
using namespace std;

int n, s, ans, arr[20];

void func(int pos, int sum, int cnt){
    if(sum == s && cnt > 0) ans++;
    for(int i = pos; i < n; i++){
        func(i + 1, sum + arr[i], cnt + 1);
    }
}

int main(){
    cin >> n >> s;
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    func(0, 0, 0);
    printf("%d", ans);
    return 0;
}