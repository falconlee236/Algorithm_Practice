#include <iostream>

using namespace std;

int main(){
    int n; cin >> n;
    int m[1001] = {1, 1, 0, };
    
    for(int i = 2; i < n + 1; i++) m[i] = (m[i - 1] + m[i - 2]) % 10007;
    cout << m[n] << endl;
    return 0;
}
