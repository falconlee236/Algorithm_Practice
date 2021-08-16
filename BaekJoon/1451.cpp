/*1451*/
/*Got it!*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int arr[100][100] = {};

long long partial_sum(int row_s, int row_e, int col_s, int col_e){
    long long res = 0;
    for(int i = col_s; i < col_e; i++){
        for(int j = row_s; j < row_e; j++){
            res += arr[i][j];
        }
    }
    return res;
}


int main() {
    int n, m; scanf("%d %d", &n, &m);
    getchar();
    for(int i = 0; i < n; i++){
        string str; getline(cin, str);
        for(int j = 0; str[j] != '\0'; j++) arr[i][j] = str[j] - '0';
    }
    
    long long ans = 0;
    long long a, b, c;
    if(n == 1){
        for(int i = 0; i < m - 2; i++){
            for(int j = i + 1; j < m - 1; j++){
                for(int k = j + 1; k < m; k++){
                    a = partial_sum(i, j, 0, n);
                    b = partial_sum(j, k, 0, n);
                    c = partial_sum(k, m, 0, n);
                    ans = max(ans, a * b * c);
                }
            }
        }
    }
    else if(m == 1){
        for(int i = 0; i < n - 2; i++){
            for(int j = i + 1; j < n - 1; j++){
                for(int k = j + 1; k < n; k++){
                    a = partial_sum(0, m, i, j);
                    b = partial_sum(0, m, j, k);
                    c = partial_sum(0, m, k, n);
                    ans = max(ans, a * b * c);
                }
            }
        }
    }
    else{
        long long answer[6] = {};
        for(int i = 0; i < m - 2; i++){
            for(int j = i + 1; j < m - 1; j++){
                for(int k = j + 1; k < m; k++){
                    a = partial_sum(i, j, 0, n);
                    b = partial_sum(j, k, 0, n);
                    c = partial_sum(k, m, 0, n);
                    answer[0] = max(answer[0], a * b * c);
                }
            }
        }
        for(int i = 0; i < n - 2; i++){
            for(int j = i + 1; j < n - 1; j++){
                for(int k = j + 1; k < n; k++){
                    a = partial_sum(0, m, i, j);
                    b = partial_sum(0, m, j, k);
                    c = partial_sum(0, m, k, n);
                    answer[1] = max(answer[1], a * b * c);
                }
            }
        }
        for(int i = 1; i < m; i++){
            a = partial_sum(0, i, 0, n);
            for(int j = 1; j < n; j++){
                b = partial_sum(i, m, 0, j);
                c = partial_sum(i, m, j, n);
                answer[2] = max(answer[2], a * b * c);
            }
        }
        for(int i = m - 1; i > 0; i--){
            a = partial_sum(i, m, 0, n);
            for(int j = 1; j < n; j++){
                b = partial_sum(0, i, 0, j);
                c = partial_sum(0, i, j, n);
                answer[3] = max(answer[3], a * b * c);
            }
        }
        for(int i = n - 1; i > 0; i--){
            a = partial_sum(0, m, i, n);
            for(int j = 1; j < m; j++){
                b = partial_sum(0, j, 0, i);
                c = partial_sum(j, m, 0, i);
                answer[4] = max(answer[4], a * b * c);
            }
        }
        for(int i = 1; i < n; i++){
            a = partial_sum(0, m, 0, i);
            for(int j = 1; j < n; j++){
                b = partial_sum(0, j, i, n);
                c = partial_sum(j, m, i, n);
                answer[5] = max(answer[5], a * b * c);
            }
        }
        ans = *max_element(answer, answer + 6);
    }
    printf("%lld", ans);

	return 0;
}
