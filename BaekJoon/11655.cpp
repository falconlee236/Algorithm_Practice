/*11655*/
/*Got it!*/
#include <iostream>
#include <string>
using namespace std;

int main(){
    string str; getline(cin, str);
    char c[100] = {0, };
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] >= 65 && str[i] <= 90){
            int tmp = str[i] + 13;
            if(tmp > 90) tmp = tmp % 91 + 65;
            c[i] = (char)tmp;
        }
        else if(str[i] >= 97 && str[i] <= 122){
            int tmp = str[i] + 13;
            if(tmp > 122) tmp = tmp % 123 + 97;
            c[i] = (char)tmp;
        }
        else c[i] = str[i];
    }
    c[str.size()] = '\0';
    printf("%s", c);
    return 0;
}