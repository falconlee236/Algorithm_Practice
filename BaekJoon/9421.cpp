#include <iostream>
#include <cstring>
using namespace std;
int arr[1000001];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for(int i = 2; i * i <= n; i++){
        if (arr[i]) continue;
        for(int j = i * i; j <= n; j += i) arr[j] = 1;
    }
    for(int i = 2; i <= n; i++){
        if (arr[i]) continue;
        int visited[1001];
        memset(visited, 0, sizeof(visited));
        int flag = 1, tmp = i, ans = 0;
        while (1){
            while(tmp){
                int num = tmp % 10;
                ans += num * num;
                tmp /= 10;
            }
            if (ans == 1 || visited[ans]) {
                if (visited[ans]) flag = 0;
                break;
            }
            visited[ans] = 1;
            tmp = ans;
            ans = 0;
        }
        if (flag) cout << i << "\n";
    }
}