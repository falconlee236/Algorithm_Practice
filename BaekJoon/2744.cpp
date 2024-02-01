#include <iostream>
#include <string>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  string s; cin >> s;
  for(char x : s){
    if ('a' <= x && x <= 'z') cout << (char)(x - 32);
    else if ('A' <= x && x <= 'Z') cout << (char)(x + 32);
  }
  return 0;
}
