/*9466*/
/*Cheating*/
#include <iostream>
using namespace std;

int arr[100001];
bool visited[100001];
bool done[100001];
int res;

void dfs(int x){
    visited[x] = true;
    int y = arr[x];
    if(!visited[y]) dfs(y);
    else{
        if(!done[y]){
            for(int i = y; i != x; i = arr[i]){
                res++;
            }
            res++;
        }
    }
    done[x] = true;
}

int main(){
    int t; scanf("%d", &t);
    while(t--){
        res = 0;
        int n; scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &arr[i]);
            visited[i] = false;
            done[i] = false;
        }
        
        for(int i = 1; i <= n; i++){
            if(!visited[i]) dfs(i);
        }
        printf("%d\n", n - res);
    }
    return 0;
}