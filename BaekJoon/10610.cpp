/*10610*/
/*Got it*/
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

int main(){
    string str; cin >> str;
    if(find(str.begin(), str.end(), '0') == str.end()){
        printf("-1");
        return 0;
    }
    int res = 0;
    for(int i = 0; str[i] != '\0'; i++){
        res += str[i] - '0';
    }
    if(res % 3 == 0){
        sort(str.begin(), str.end(), greater<>());
        cout << str;
    }
    else printf("-1");
    return 0;
}