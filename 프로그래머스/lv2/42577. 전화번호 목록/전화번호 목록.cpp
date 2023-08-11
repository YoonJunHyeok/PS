#include <bits/stdc++.h>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    set<string> s(phone_book.begin(), phone_book.end());
    
    for(auto iter = s.begin(); iter != s.end(); iter++) {
        string lhs = *iter++;
        if(iter == s.end()) break;
        string rhs = *iter--;
        
        if(lhs.length() > rhs.length()) continue;
        
        string rhs_sub = rhs.substr(0, lhs.length());
        if(lhs.compare(rhs_sub) == 0) {
            answer = false;
            break;
        }
    }
    
    
    return answer;
}