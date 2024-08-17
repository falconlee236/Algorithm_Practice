#include <iostream>
using namespace std;
int arr[7][8];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int x, winner = 0, tmp = 0;
    for(int t = 1; t <= 21 * 2; t++){
        cin >> x;
        for(int i = 6; i > 0; i--){
            if (!arr[i][x]){
                arr[i][x] = (t & 1 ? 1 : 2);
                break;
            }
        }
        // cout << x << " " << (t & 1 ? 1 : 2) << "\n";
        // for(int i = 1; i < 7; i++){
        //     for(int j = 1; j < 8; j++){
        //         cout << arr[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        for(int i = 1; i < 7; i++){
            for(int j = 1; j < 8; j++){
                int cnt = 1;
                for(int k = 1; k < 4 && j + k < 8 && arr[i][j]; k++){
                    if (arr[i][j + k] == arr[i][j]) cnt++;
                }
                if (cnt == 4 && !winner) {
                    winner = arr[i][j];
                    tmp = (t + 1) / 2;
                }
            }
        }
        // cout << winner << "\n";
        for(int i = 1; i < 7; i++){
            for(int j = 1; j < 8; j++){
                int cnt = 1;
                for(int k = 1; k < 4 && i + k < 7 && arr[i][j]; k++){
                    if (arr[i + k][j] == arr[i][j]) cnt++;
                }
                if (cnt == 4 && !winner) {
                    winner = arr[i][j];
                    tmp = (t + 1) / 2;
                }
            }
        }
        for(int i = 1; i < 7; i++){
            for(int j = 1; j < 8; j++){
                int cnt = 1;
                for(int k = 1; k < 4 && i + k < 7 && j + k < 8 && arr[i][j]; k++){
                    if (arr[i + k][j + k] == arr[i][j]) cnt++;
                }
                if (cnt == 4 && !winner) {
                    winner = arr[i][j];
                    tmp = (t + 1) / 2;
                }
            }
        }
        for(int i = 1; i < 7; i++){
            for(int j = 1; j < 8; j++){
                int cnt = 1;
                for(int k = 1; k < 4 && i - k > 0 && j + k < 8 && arr[i][j]; k++){
                    if (arr[i - k][j + k] == arr[i][j]) cnt++;
                }
                if (cnt == 4 && !winner) {
                    winner = arr[i][j];
                    tmp = (t + 1) / 2;
                }
            }
        }
    }
    cout << (!winner ? "ss" : (winner == 1 ? "sk " + to_string(tmp) : "ji " + to_string(tmp)));
}