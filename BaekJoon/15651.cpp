/*15651*/
/*Got it!*/
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;

void func(int num){
    if(num == m){
        for(int i = 0; i < m; i++) printf("%d ", v[i]);
        printf("\n");
        return;
    }
    for(int i = 1; i <= n; i++){
        v.push_back(i);
        func(num + 1);
        v.pop_back();
    }
}

int main(){
    cin >> n >> m;
    func(0);
    return 0;
}