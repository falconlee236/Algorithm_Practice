/*2869*/
/*Cheating*/
#include <iostream>
using namespace std;

int main(){
    int a, b, v; cin >> a >> b >> v;
    cout << ((v - a) % (a - b) == 0 ?  (v - a) / (a - b) + 1 : (v - a) / (a - b) + 2); 
    return 0;
}