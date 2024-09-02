#include <iostream>
using namespace std;
int main(){
    int m, n; cin >> n >> m;
    for(int i = 0; i < n - m + 1; i++) cout << i << " " << i + 1 << "\n";
    for(int i = 0; i < m - 2; i++) cout << 1 << " " << n - i - 1 << "\n";
}