#include <iostream>
#include <string>
using namespace std;

string str;

string func(int& pos){
    pos++;
    if(str[pos] == 'w' || str[pos] == 'b') return string(1, str[pos]);
    string upperleft = func(pos);
    string upperright = func(pos);
    string lowerleft = func(pos);
    string lowerright = func(pos);
    
    return "x" + lowerleft + lowerright + upperleft + upperright;
    
}

int main(){
    int t; cin >> t;
    while(t--){
        cin >> str;
        int pos = -1;
        cout << func(pos) << "\n";
    }
    return 0;
}