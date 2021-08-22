/*15652*/
/*Got it!*/
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;

void func(int size, int pos){
    if(size == m){
        for(int i = 0; i < m; i++) printf("%d ", v[i]);
        printf("\n");
        return;
    }
    for(int i = pos; i <= n; i++){
        v.push_back(i);
        func(size + 1, i);
        v.pop_back();
    }
}

int main(){
    cin >> n >> m;
    func(0, 1);
    return 0;
}