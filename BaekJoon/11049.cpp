/*11049*/
/*Got it!*/
#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int n;
int matrix[500][2];
int dp[500][500];

int cal(int start, int end){
    if(end == start) return 0;
    if(end - start == 1){
        return matrix[start][0] * matrix[end][0] * matrix[end][1];
    }
    int& ret = dp[start][end];
    if(ret != 0) return ret;
    ret = INF;
    for(int i = start; i < end; i++){
        int a = cal(start, i);
        int b = cal(i + 1, end);
        if(a == 0){
            int res = matrix[start][0] * matrix[start][1] * matrix[end][1];
            ret = min(ret, res + b);
        }
        else if(b == 0){
            int res = matrix[start][0] * matrix[end][0] * matrix[end][1];
            ret = min(ret, a + res);
        }
        else{
            int res = matrix[start][0] * matrix[i][1] * matrix[end][1];
            ret = min(ret, a + b + res);
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> matrix[i][0] >> matrix[i][1];
    cout << cal(0, n - 1) << "\n";
    return 0;
}