/*9252*/
/*Cheating*/
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

int lcs[1001][1001];

int main(){
    string a, b; cin >> a >> b;
    for(int i = 1; i <= a.size(); i++){
        for(int j = 1; j <= b.size(); j++){
            char x = a[i - 1], y = b[j - 1];
            if(x == y) lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
        }
    }
    
    int pos[2][2] = {{-1, 0}, {0, -1}};
    int nrow = a.size(), ncol = b.size();
    printf("%d\n", lcs[nrow][ncol]);
    stack<char> stk;
    while(lcs[nrow][ncol]){
        if(lcs[nrow][ncol] == lcs[nrow + pos[0][0]][ncol + pos[0][1]]){
            nrow += pos[0][0];
            ncol += pos[0][1];
        }
        else if(lcs[nrow][ncol] == lcs[nrow + pos[1][0]][ncol + pos[1][1]]){
            nrow += pos[1][0];
            ncol += pos[1][1];
        }
        else{
            nrow -= 1;
            ncol -= 1;
            stk.push(a[nrow]);
        }
    }
    

    while(!stk.empty()){
        printf("%c", stk.top());
        stk.pop();
    }
    return 0;
}