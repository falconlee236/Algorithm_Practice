#include <iostream>
#include <string>
using namespace std;

bool row[9][10], col[9][10], square[9][10];
int arr[9][9];

void func(int n){
    if(n == 81){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++) cout << arr[i][j];
            cout << "\n";
        }
        exit(0);
    }
    int r = n / 9, c = n % 9;
    if(!arr[r][c]){
        for(int i = 1; i <= 9; i++){
            if(!row[r][i] && !col[c][i] && !square[(r / 3) * 3 + c / 3][i]){
                row[r][i] = true;
                col[c][i] = true;
                square[(r / 3) * 3 + c / 3][i] = true;
                arr[r][c] = i;
                func(n + 1);
                arr[r][c] = 0;
                square[(r / 3) * 3 + c / 3][i] = false;
                col[c][i] = false;
                row[r][i] = false;
            }
        }
    }
    else func(n + 1);
}


int main(){
    for(int i = 0; i < 9; i++){
        string str; getline(cin, str);
        for(int j = 0; j < 9; j++){
            int num = str[j] - '0';
            arr[i][j] = num;
            row[i][num] = true;
            col[j][num] = true;
            square[(i / 3) * 3 + j / 3][num] = true;
        }
    }
    func(0);
}