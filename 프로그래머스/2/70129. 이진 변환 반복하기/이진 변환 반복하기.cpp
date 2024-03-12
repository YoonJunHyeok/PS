#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2, 0); // 변환 횟수, 제거된 0의 개수
    
    while(1) {
        if(s.compare("1") == 0) break;
        
        string tmp = "";
        for(char c: s) {
            if(c == '1') tmp += c;
            else answer[1]++;
        }
        
        int len = tmp.length();
        
        s = "";
        while(len > 0) {
            s = to_string(len % 2) + s;
            len /= 2;
        }
        
        answer[0]++;
    }
    
    return answer;
}