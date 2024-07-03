#include <iostream>
using namespace std;
int main(void){
    int T; cin >> T;
    while (T--){
        string str; cin >> str;
        int idx = 0;
        if (str[0] == 'B' || str[0] == 'D' || str[0] == 'E') idx++;
        while (str[idx] == 'A') idx++;
        while (str[idx] == 'F') idx++;
        while (str[idx] == 'C') idx++;
        if (str[idx] == 'A' || str[idx] == 'B' || str[idx] == 'C' || str[idx] == 'D' || str[idx] == 'E' || str[idx] == 'F') idx++;
        cout << (idx == str.length() ? "Infected!\n" : "Good\n");
    }
}

// #include <iostream>
// #include <regex>
// using namespace std;
// int main(void){
//     int T; cin >> T;
//     regex re(R"([A-F]?A+F+C+[A-F]?$)");
//     while (T--){
//         string str; cin >> str;
//         cout << (regex_match(str, re) ? "Infected!\n" : "Good\n");
//     }
// }