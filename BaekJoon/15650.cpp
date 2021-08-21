/*15650*/
/*Got it!*/
#include <iostream>
#include <vector>
using namespace std;

int arr[9];
int n, m;
vector<int> v;

void func(int pos, int cnt){
    if(cnt == m){
        for(int i = 0; i < m; i++) printf("%d ", v[i]);
        printf("\n");
        return;
    }
    for(int i = pos; i <= n; i++){
        v.push_back(i);
        func(i + 1, cnt + 1);
        v.pop_back();
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) arr[i] = i;
    func(1, 0);
}