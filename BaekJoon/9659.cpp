#include <iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long n; cin >> n;
    cout << (n % 2 ? "SK" : "CY") << "\n";
}