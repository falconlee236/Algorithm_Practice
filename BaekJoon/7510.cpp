#include <cstdio>

int main(){
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        printf("Scenario #%d:\n", i);
        int s_a = a * a, s_b = b * b, s_c = c * c;
        if(s_a + s_b == s_c || s_a + s_c == s_b || s_b + s_c == s_a) printf("yes\n\n");
        else printf("no\n\n");
    }
    return 0;
}