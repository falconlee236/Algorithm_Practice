#include <iostream>
using namespace std;
int main(void){
    int n, m = 0, w = 0; cin >> n;
    string str; cin >> str;
    for(size_t i = 0; i < str.size(); i++){
        if (str[i] == 'M') m++;
        else w++;
        if (abs(m - w) > n){
            if (i == str.size() - 1){
                if (str[i] == 'M') m--;
                else w--;
                break;
            }
            if (str[i] == str[i + 1]){
                if (str[i] == 'M') m--;
                else w--;
                break;
            }
            if (str[i] == 'M') m--;
            else w--;
            swap(str[i], str[i + 1]);
            i--;
        }
    }
    cout << m + w;
}