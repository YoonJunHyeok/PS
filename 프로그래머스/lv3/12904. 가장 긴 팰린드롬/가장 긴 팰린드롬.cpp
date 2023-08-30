#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = 0;
    int len = s.length();
    
    for(int i = 0; i < len; i++) {
        // even len - i, i+1 are center
        int st1 = i, st2 = i + 1;
        int tmpLen = 0;
        while(st1 >= 0 && st2 < len && s[st1] == s[st2]) {
            tmpLen += 2;
            st1--;
            st2++;
        }
        answer = max(answer, tmpLen);
        
        // odd len - i is center
        st1 = i - 1, st2 = i + 1;
        tmpLen = 1;
        while(st1 >= 0 && st2 < len && s[st1] == s[st2]) {
            tmpLen += 2;
            st1--;
            st2++;
        }
        answer = max(answer, tmpLen);
    }
        
    return answer;
}