#include<iostream>
using namespace std;
int arr[1001];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    for(int i = 2; i * i <= 1000; i++){
        if (arr[i]) continue;
        for(int j = i * i; j <= 1000; j += i) arr[j] = 1;
    }
    int a, b, c, d, x = 0, y = 0, z = 0; cin >> a >> b >> c >> d;
    for(int i = a; i <= b; i++){
        if (arr[i]) continue;
        if (c <= i && i <= d) y++;
        else x++;
    }
    for(int i = c; i <= d; i++){
        if (arr[i] || (a <= i && i <= b)) continue;
        z++;
    }
    if (y % 2 == 0) cout << (x <= z ? "yj" : "yt"); 
    else cout << (x < z ? "yj" : "yt");
}