#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int l, c; cin >> l >> c;
    vector<char> alpha;
    int cons_size = 0, vowel_size = 0;
    for(int i = 0; i < c; i++){
        char ch; scanf("%c", &ch);
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') vowel_size++;
        else cons_size++;
        alpha.push_back(ch);
    }
    sort(alpha.begin(), alpha.end());
    
    for(int i = 1; i <= vowel_size; i++){
        if(cons_size - i < 2) continue;
        
    }
    
}