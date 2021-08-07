/*10808*/
/*Got it!*/
#include <iostream>
#include <string>
using namespace std;

int main(){
    string str; cin >> str;
    cin.clear();
    int arr[26] = {};
    for(int i = 0; str[i] != '\0'; i++) arr[str[i] - 'a']++;;
    for(int i = 0; i < 26; i++) printf("%d ", arr[i]);
    return 0;
}