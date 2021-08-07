/*11656*/
/*Got it!*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    string str; cin >> str;
    vector<string> v;
    for(int i = 0; str[i] != '\0'; i++){
        v.push_back(str.substr(i));
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++) cout << v[i] << "\n";
    return 0;
}