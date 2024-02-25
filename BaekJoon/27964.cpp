#include <iostream>
#include <string>
#include <set>
using namespace std;
int main(){
    int n; cin >> n;
    int tmp = 0;
    set<string> ss;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        ss.insert(s);
    }
    for (auto x : ss){
        if (x.find("Cheese", x.length() - 6) != string::npos) tmp++;
    }
    cout << (tmp >= 4 ? "yummy" : "sad");
}
