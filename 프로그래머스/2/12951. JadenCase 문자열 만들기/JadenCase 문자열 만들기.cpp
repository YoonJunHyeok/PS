#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    answer += toupper(s[0]);
    for(int idx = 1; idx < s.length(); idx++) {
        if(s[idx - 1] == ' ') answer += toupper(s[idx]);
        else answer += tolower(s[idx]);
    }
    
    return answer;
}