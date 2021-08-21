/*15649*/
/*Cheating*/
#include <iostream>
#include <vector>
using namespace std;

int n, m;
int arr[9];
int visit[9];
vector<int> res;

void func(int cnt){
    if(cnt == m){
        for(int i = 0; i < m; i++) printf("%d ", res[i]);
        printf("\n");
        return;
    }
    for(int i = 1; i <= n; i++){
       if(visit[i]) continue;
       visit[i] = 1;
       res.push_back(i);
       func(cnt + 1);
       res.pop_back();
       visit[i] = 0;
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) arr[i] = i;
    func(0);
    return 0;
}