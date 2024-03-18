#include <string>
#include <vector>

using namespace std;

int last_zero_index(string str) {
    int len = str.length();
    
    for(int idx = len - 1; idx >= 0; idx--) {
        if(str[idx] == '0') {
            return idx;
        }
    }
    
    return -1;
}

vector<string> solution(vector<string> s) {
    vector<string> answer;
    
    for(string str: s) {
        string ans = "", tmp = "";
        int len = str.length();
        
        for(int idx = 0; idx < len; idx++) {
            ans += str[idx];
            if(ans.length() >= 3 && ans.substr(ans.length() - 3, 3) == "110") {
                ans.erase(ans.length() - 3, 3);
                tmp += "110";
            }
        }
        
        int lastIdx = last_zero_index(ans);
        ans.insert(lastIdx + 1, tmp);     
        
        answer.push_back(ans);
    }
    
    return answer;
}