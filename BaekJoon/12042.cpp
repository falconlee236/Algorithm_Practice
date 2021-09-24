/*12042*/
/*Got it!*/
/*00:20*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++){
	    string str; cin >> str;
	    if(str.size() == 1){
	        printf("Case #%d: %d\n", i, 1);
	        continue;
	    }
	    
	    int sum = 1;
	    for(int i = 0; str[i] != '\0'; i++){
	        int cnt = 0;
	        if(i == 0){
	            if(str[0] != str[1]) cnt = 2;
	            else cnt = 1;
	        }else if(i == str.size() - 1){
	            if(str[str.size() - 1] != str[str.size() - 2]) cnt = 2;
	            else cnt = 1;
	        }else{
	            int alpha[26] = {};
	            alpha[str[i - 1] - 'a']++;
	            alpha[str[i] - 'a']++;
	            alpha[str[i + 1] - 'a']++;
	            for(int i = 0; i < 26; i++){
	                if(alpha[i]) cnt++;
	            }
	        }
	        sum *= cnt;
	    }
	    printf("Case #%d: %d\n", i, sum);
	}
	return 0;
}
