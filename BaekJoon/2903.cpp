#include <iostream>
#include <cmath>
using namespace std;
int main(){int n; cin >> n; int num = static_cast<int>(pow(2, n - 1)); cout << (num + num + 1) * (num + num + 1);}