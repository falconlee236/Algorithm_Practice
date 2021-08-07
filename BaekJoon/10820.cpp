/*10820*/
/*Got it!*/
#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    while(getline(cin, str)){
        cin.clear();
        int arr[4] = {};
        for(int i = 0; str[i] != '\0'; i++){
            if(str[i] == ' ') arr[3]++;
            else if(str[i] >= 48 && str[i] <= 57) arr[2]++;
            else if(str[i] >= 65 && str[i] <= 90) arr[1]++;
            else arr[0]++;
        }
        printf("%d %d %d %d\n", arr[0], arr[1], arr[2], arr[3]);
    }
}