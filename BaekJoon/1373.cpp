/*1373*/
/*Got it!*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(){
    cin.tie(0); cin.sync_with_stdio(false);
    string str; cin >> str;
    vector<string> v;
    for(int i = str.size(); i > 0; i-=3){
        if(i - 3 < 0) v.push_back(str.substr(0, i));
        else v.push_back(str.substr(i - 3, 3));
    }
    int s[3] = {1, 2, 4};
    reverse(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        int res = 0;
        reverse(v[i].begin(), v[i].end());
        for(int j = 0; j < v[i].size(); j++){
            res += ((v[i][j] - '0') * s[j]);
        }
        printf("%d", res);
    }
    return 0;
}